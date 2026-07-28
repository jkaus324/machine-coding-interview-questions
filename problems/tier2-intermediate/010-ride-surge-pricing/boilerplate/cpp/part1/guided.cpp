#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


// Data class (given).
struct PricingContext {
    double baseFare;
    int availableDrivers;
    int activeRideRequests;
    string timeOfDay;
    string weather;
    PricingContext(double baseFare_, int availableDrivers_, int activeRideRequests_, const string& timeOfDay_, const string& weather_)
      : baseFare(baseFare_), availableDrivers(availableDrivers_), activeRideRequests(activeRideRequests_), timeOfDay(timeOfDay_), weather(weather_) {}
};

struct RideRequest {
    string userId;
    string pickup;
    string dropoff;
    string rideType;
    RideRequest(const string& userId_, const string& pickup_, const string& dropoff_, const string& rideType_)
      : userId(userId_), pickup(pickup_), dropoff(dropoff_), rideType(rideType_) {}
};

// HINT: introduce an abstraction so new variants don't change existing code.
// HINT: keep each piece small — one responsibility per class.

// HINT: start from what this must return, then work backwards to the state it needs.
double calculateSurge(PricingContext ctx) {
    // TODO: write your solution
    return {};
}

// HINT: start from what this must return, then work backwards to the state it needs.
double calculateFare(RideRequest req, PricingContext ctx) {
    // TODO: write your solution
    return {};
}
