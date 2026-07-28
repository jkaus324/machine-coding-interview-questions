// Notification System — Observer + Decorator reference solution (JavaScript).

const PRIORITY_ORDER = ["promotional", "info", "critical"];

// Every actual delivery is recorded as "<channel>:<userId>". This is what the
// tests assert on — it makes fan-out and filtering observable.
let SENT_LOG = [];

function recordSend(channel, userId) {
  SENT_LOG.push(`${channel}:${userId}`);
}

function priorityLevel(p) {
  const idx = PRIORITY_ORDER.indexOf(p);
  return idx >= 0 ? idx : 0;
}

class User {
  constructor(id, email, phone, subscribedChannels) {
    this.id = id;
    this.email = email;
    this.phone = phone;
    this.subscribedChannels = subscribedChannels;
  }
}

class NotificationObserver {
  channelName() { throw new Error('not implemented'); }
  send(userId, message) { throw new Error('not implemented'); }
  update(event, priority, user) { throw new Error('not implemented'); }
}

class EmailNotifier extends NotificationObserver {
  channelName() { return "email"; }
  send(userId, message) { recordSend("email", userId); }
  update(event, priority, user) { recordSend("email", user.id); }
}

class SMSNotifier extends NotificationObserver {
  channelName() { return "sms"; }
  send(userId, message) { recordSend("sms", userId); }
  update(event, priority, user) { recordSend("sms", user.id); }
}

class PushNotifier extends NotificationObserver {
  channelName() { return "push"; }
  send(userId, message) { recordSend("push", userId); }
  update(event, priority, user) { recordSend("push", user.id); }
}

// Wraps ANY observer. The concrete notifiers never learn priority exists.
class PriorityFilteredObserver extends NotificationObserver {
  constructor(inner, minPriority) {
    super();
    this.inner = inner;
    this.minPriority = minPriority;
  }
  channelName() { return this.inner.channelName(); }
  send(userId, message) { this.inner.send(userId, message); }
  update(event, priority, user) {
    if (priorityLevel(priority) >= priorityLevel(this.minPriority)) {
      this.inner.update(event, priority, user);
    }
  }
}

class NotificationManager {
  constructor() {
    this.observers = [];
  }
  subscribe(obs) { this.observers.push(obs); }
  unsubscribe(channel) {
    this.observers = this.observers.filter(o => o.channelName() !== channel);
  }
  notify(event, users) {
    for (const u of users) {
      for (const obs of this.observers) {
        if (u.subscribedChannels.includes(obs.channelName())) {
          obs.send(u.id, event);
        }
      }
    }
  }
  notifyAll(event, priority, users) {
    for (const u of users) {
      for (const obs of this.observers) {
        if (u.subscribedChannels.includes(obs.channelName())) {
          obs.update(event, priority, u);
        }
      }
    }
  }
}

function notify(event, users) {
  const mgr = new NotificationManager();
  mgr.subscribe(new EmailNotifier());
  mgr.subscribe(new SMSNotifier());
  mgr.subscribe(new PushNotifier());
  mgr.notify(event, users);
}

function notify_with_priority(event, priority, users, userMinPriority) {
  const minP = userMinPriority.has("*") ? userMinPriority.get("*") : "promotional";
  const mgr = new NotificationManager();
  mgr.subscribe(new PriorityFilteredObserver(new EmailNotifier(), minP));
  mgr.subscribe(new PriorityFilteredObserver(new SMSNotifier(), minP));
  mgr.subscribe(new PriorityFilteredObserver(new PushNotifier(), minP));
  mgr.notifyAll(event, priority, users);
}

// ─── Entry points the test harness calls (from spec.yaml) ───────────────────

function buildUsers(userIds, subscribedChannels) {
  return userIds.map(uid =>
    new User(uid, `${uid}@test.com`, "+1-555-0000", [...subscribedChannels]));
}

function reset_service() {
  SENT_LOG = [];
}

function notify_event(event, userIds, subscribedChannels) {
  notify(event, buildUsers(userIds, subscribedChannels));
}

function notify_priority(event, priority, userIds, subscribedChannels, minPriority) {
  const prefs = new Map();
  if (minPriority) {
    prefs.set("*", minPriority);
  }
  notify_with_priority(event, priority, buildUsers(userIds, subscribedChannels), prefs);
}

function notify_priority_level(p) {
  return priorityLevel(p);
}

function get_sent_log() {
  return [...SENT_LOG];
}

module.exports = {
  User,
  NotificationObserver,
  EmailNotifier,
  SMSNotifier,
  PushNotifier,
  PriorityFilteredObserver,
  NotificationManager,
  reset_service,
  notify_event,
  notify_priority,
  notify_priority_level,
  get_sent_log,
};
