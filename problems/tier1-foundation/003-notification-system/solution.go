// Notification System — Observer + Decorator reference solution (Go).
package main

var priorityOrder = []string{"promotional", "info", "critical"}

// Every actual delivery is recorded as "<channel>:<userId>". This is what the
// tests assert on — it makes fan-out and filtering observable.
var sentLog []string

func recordSend(channel, userID string) {
	sentLog = append(sentLog, channel+":"+userID)
}

func priorityLevel(p string) int {
	for i, v := range priorityOrder {
		if v == p {
			return i
		}
	}
	return 0
}

type nsUser struct {
	id                 string
	subscribedChannels []string
}

type notificationObserver interface {
	channelName() string
	send(userID, message string)
	update(event, priority string, user nsUser)
}

type emailNotifier struct{}

func (emailNotifier) channelName() string                     { return "email" }
func (emailNotifier) send(userID, message string)             { recordSend("email", userID) }
func (emailNotifier) update(event, priority string, u nsUser) { recordSend("email", u.id) }

type smsNotifier struct{}

func (smsNotifier) channelName() string                     { return "sms" }
func (smsNotifier) send(userID, message string)             { recordSend("sms", userID) }
func (smsNotifier) update(event, priority string, u nsUser) { recordSend("sms", u.id) }

type pushNotifier struct{}

func (pushNotifier) channelName() string                     { return "push" }
func (pushNotifier) send(userID, message string)             { recordSend("push", userID) }
func (pushNotifier) update(event, priority string, u nsUser) { recordSend("push", u.id) }

// priorityFilteredObserver wraps ANY observer. The concrete notifiers above
// never learn that priority exists.
type priorityFilteredObserver struct {
	inner       notificationObserver
	minPriority string
}

func (p priorityFilteredObserver) channelName() string { return p.inner.channelName() }

func (p priorityFilteredObserver) send(userID, message string) { p.inner.send(userID, message) }

func (p priorityFilteredObserver) update(event, priority string, u nsUser) {
	if priorityLevel(priority) >= priorityLevel(p.minPriority) {
		p.inner.update(event, priority, u)
	}
}

func contains(list []string, s string) bool {
	for _, v := range list {
		if v == s {
			return true
		}
	}
	return false
}

func buildUsers(userIds []string, subscribedChannels []string) []nsUser {
	users := make([]nsUser, 0, len(userIds))
	for _, uid := range userIds {
		users = append(users, nsUser{id: uid, subscribedChannels: subscribedChannels})
	}
	return users
}

// ─── Entry points the test harness calls (from spec.yaml) ───────────────────

func reset_service() {
	sentLog = nil
}

func notify_event(event string, userIds []string, subscribedChannels []string) {
	observers := []notificationObserver{emailNotifier{}, smsNotifier{}, pushNotifier{}}
	for _, u := range buildUsers(userIds, subscribedChannels) {
		for _, obs := range observers {
			if contains(u.subscribedChannels, obs.channelName()) {
				obs.send(u.id, event)
			}
		}
	}
}

func notify_priority(event, priority string, userIds []string, subscribedChannels []string, minPriority string) {
	minP := minPriority
	if minP == "" {
		minP = "promotional"
	}
	observers := []notificationObserver{
		priorityFilteredObserver{emailNotifier{}, minP},
		priorityFilteredObserver{smsNotifier{}, minP},
		priorityFilteredObserver{pushNotifier{}, minP},
	}
	for _, u := range buildUsers(userIds, subscribedChannels) {
		for _, obs := range observers {
			if contains(u.subscribedChannels, obs.channelName()) {
				obs.update(event, priority, u)
			}
		}
	}
}

func notify_priority_level(p string) int {
	return priorityLevel(p)
}

func get_sent_log() []string {
	out := make([]string, len(sentLog))
	copy(out, sentLog)
	return out
}
