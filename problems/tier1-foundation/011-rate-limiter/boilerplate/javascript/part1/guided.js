// Data class (given).

// HINT: introduce an abstraction so new rules don't change existing code.

// HINT: start from what this must return, then work backwards to the state it needs.
function reset_service() {
  // TODO: write your solution
  return null;
}

// HINT: start from what this must return, then work backwards to the state it needs.
function init_limiter(maxRequests, windowSize) {
  // TODO: write your solution
  return null;
}

// HINT: start from what this must return, then work backwards to the state it needs.
function allow_request_simple(clientId, timestamp, endpoint) {
  // TODO: write your solution
  return null;
}

// HINT: start from what this must return, then work backwards to the state it needs.
function get_request_count(clientId) {
  // TODO: write your solution
  return null;
}

// ── Export everything the test runner needs (do not remove) ──
// If you add classes (e.g. strategy subclasses), add them here too.
module.exports = { reset_service, init_limiter, allow_request_simple, get_request_count };
