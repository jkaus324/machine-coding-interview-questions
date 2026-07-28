#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


// Data class (given).

// HINT: introduce an abstraction so new variants don't change existing code.
// HINT: keep each piece small — one responsibility per class.

// HINT: start from what this must return, then work backwards to the state it needs.
void reset_service() {
    // TODO: write your solution
    // nothing to return
}

// HINT: start from what this must return, then work backwards to the state it needs.
void init_limiter(int maxRequests, int windowSize) {
    // TODO: write your solution
    // nothing to return
}

// HINT: start from what this must return, then work backwards to the state it needs.
bool allow_request_simple(string clientId, int timestamp, string endpoint) {
    // TODO: write your solution
    return {};
}

// HINT: start from what this must return, then work backwards to the state it needs.
int get_request_count(string clientId) {
    // TODO: write your solution
    return {};
}

// HINT: start from what this must return, then work backwards to the state it needs.
bool allow_request_with_strategy_simple(string algorithm, string clientId, int timestamp, string endpoint) {
    // TODO: write your solution
    return {};
}

// HINT: start from what this must return, then work backwards to the state it needs.
bool allow_request_for_tier_str(string tier, string clientId, int timestamp, string endpoint) {
    // TODO: write your solution
    return {};
}
