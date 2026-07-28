#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// ─── Data Model ─────────────────────────────────────────────────────────────

struct User {
    string id;
    string email;
    string phone;
    vector<string> subscribedChannels;
};

// ─── Delivery Log ───────────────────────────────────────────────────────────
// Every actual delivery is recorded as "<channel>:<userId>". This is what the
// tests assert on — it makes fan-out and filtering observable.

static vector<string> SENT_LOG;

static void recordSend(const string& channel, const string& userId) {
    SENT_LOG.push_back(channel + ":" + userId);
}

// ─── Priority Helpers ───────────────────────────────────────────────────────

const vector<string> PRIORITY_ORDER = {"promotional", "info", "critical"};

int priorityLevel(const string& p) {
    for (int i = 0; i < (int)PRIORITY_ORDER.size(); i++)
        if (PRIORITY_ORDER[i] == p) return i;
    return 0;                      // unknown -> treat as lowest
}

// ─── Observer Interface ─────────────────────────────────────────────────────

class NotificationObserver {
public:
    virtual void send(const string& userId, const string& message) = 0;
    virtual void update(const string& event, const string& priority,
                        const User& user) = 0;
    virtual string channelName() const = 0;
    virtual ~NotificationObserver() = default;
};

// ─── Concrete Observers ─────────────────────────────────────────────────────

class EmailNotifier : public NotificationObserver {
public:
    string channelName() const override { return "email"; }

    void send(const string& userId, const string& message) override {
        recordSend("email", userId);
    }

    void update(const string& event, const string& priority,
                const User& user) override {
        recordSend("email", user.id);
    }
};

class SMSNotifier : public NotificationObserver {
public:
    string channelName() const override { return "sms"; }

    void send(const string& userId, const string& message) override {
        recordSend("sms", userId);
    }

    void update(const string& event, const string& priority,
                const User& user) override {
        recordSend("sms", user.id);
    }
};

class PushNotifier : public NotificationObserver {
public:
    string channelName() const override { return "push"; }

    void send(const string& userId, const string& message) override {
        recordSend("push", userId);
    }

    void update(const string& event, const string& priority,
                const User& user) override {
        recordSend("push", user.id);
    }
};

// ─── Priority Filter Decorator (Part 2) ─────────────────────────────────────
// Wraps ANY observer. The concrete notifiers above never learn priority exists.

class PriorityFilteredObserver : public NotificationObserver {
private:
    NotificationObserver* inner;
    string minPriority;
public:
    PriorityFilteredObserver(NotificationObserver* obs, const string& minP)
        : inner(obs), minPriority(minP) {}

    string channelName() const override { return inner->channelName(); }

    void send(const string& userId, const string& message) override {
        inner->send(userId, message);
    }

    void update(const string& event, const string& priority,
                const User& user) override {
        if (priorityLevel(priority) >= priorityLevel(minPriority)) {
            inner->update(event, priority, user);
        }
    }
};

// ─── Notification Manager (the Subject) ─────────────────────────────────────

class NotificationManager {
private:
    vector<NotificationObserver*> observers;
public:
    void subscribe(NotificationObserver* obs) {
        observers.push_back(obs);
    }

    void unsubscribe(const string& channel) {
        observers.erase(
            remove_if(observers.begin(), observers.end(),
                [&](NotificationObserver* obs) {
                    return obs->channelName() == channel;
                }),
            observers.end());
    }

    // Part 1 — fan out to each user's subscribed channels
    void notify(const string& event, const vector<User>& users) {
        for (auto& user : users) {
            for (auto* obs : observers) {
                auto& ch = user.subscribedChannels;
                if (find(ch.begin(), ch.end(), obs->channelName()) != ch.end()) {
                    obs->send(user.id, event);
                }
            }
        }
    }

    // Part 2 — priority-aware fan out
    void notifyAll(const string& event, const string& priority,
                   const vector<User>& users) {
        for (auto& user : users) {
            for (auto* obs : observers) {
                auto& ch = user.subscribedChannels;
                if (find(ch.begin(), ch.end(), obs->channelName()) != ch.end()) {
                    obs->update(event, priority, user);
                }
            }
        }
    }
};

// ─── Free Function: Part 1 ─────────────────────────────────────────────────

void notify(const string& event, const vector<User>& users) {
    EmailNotifier email;
    SMSNotifier   sms;
    PushNotifier  push;

    NotificationManager mgr;
    mgr.subscribe(&email);
    mgr.subscribe(&sms);
    mgr.subscribe(&push);
    mgr.notify(event, users);
}

// ─── Free Function: Part 2 (priority filtering) ────────────────────────────

void notify(const string& event, const string& priority,
            const vector<User>& users,
            const unordered_map<string, string>& userMinPriority) {
    string minP = userMinPriority.count("*") ? userMinPriority.at("*") : "promotional";

    EmailNotifier email;
    SMSNotifier   sms;
    PushNotifier  push;

    PriorityFilteredObserver fe(&email, minP);
    PriorityFilteredObserver fs(&sms,   minP);
    PriorityFilteredObserver fp(&push,  minP);

    NotificationManager mgr;
    mgr.subscribe(&fe);
    mgr.subscribe(&fs);
    mgr.subscribe(&fp);
    mgr.notifyAll(event, priority, users);
}

// ─── Entry points the test harness calls (from spec.yaml) ───────────────────

static vector<User> buildUsers(const vector<string>& userIds,
                               const vector<string>& subscribedChannels) {
    vector<User> users;
    for (size_t i = 0; i < userIds.size(); i++) {
        User u;
        u.id    = userIds[i];
        u.email = userIds[i] + "@test.com";
        u.phone = "+1-555-0000";
        u.subscribedChannels = subscribedChannels;
        users.push_back(u);
    }
    return users;
}

void reset_service() {
    SENT_LOG.clear();
}

void notify_event(const string& event, const vector<string>& userIds,
                  const vector<string>& subscribedChannels) {
    notify(event, buildUsers(userIds, subscribedChannels));
}

void notify_priority(const string& event, const string& priority,
                     const vector<string>& userIds,
                     const vector<string>& subscribedChannels,
                     const string& minPriority) {
    unordered_map<string, string> prefs;
    if (!minPriority.empty()) prefs["*"] = minPriority;
    notify(event, priority, buildUsers(userIds, subscribedChannels), prefs);
}

int notify_priority_level(const string& priority) {
    return priorityLevel(priority);
}

vector<string> get_sent_log() {
    return SENT_LOG;
}

// ─── Local demo — the harness defines RUNNING_TESTS, so this is skipped ─────

#ifndef RUNNING_TESTS
int main() {
    User u1 = {"user1", "user1@example.com", "+91-9000000001", {"email", "sms"}};
    User u2 = {"user2", "user2@example.com", "+91-9000000002", {"push"}};

    cout << "=== Part 1: Basic Notification ===" << endl;
    reset_service();
    notify("Order shipped", {u1, u2});
    for (auto& s : get_sent_log()) cout << "  sent -> " << s << endl;

    cout << "\n=== Part 2: Priority Filtering (min = info) ===" << endl;
    reset_service();
    unordered_map<string, string> prefs = {{"*", "info"}};
    notify("System update available", "info", {u1, u2}, prefs);
    for (auto& s : get_sent_log()) cout << "  sent -> " << s << endl;

    cout << "\n=== Part 2: Promotional blocked by info+ pref ===" << endl;
    reset_service();
    notify("50% off sale!", "promotional", {u1, u2}, prefs);
    cout << "  deliveries: " << get_sent_log().size() << endl;

    return 0;
}
#endif
