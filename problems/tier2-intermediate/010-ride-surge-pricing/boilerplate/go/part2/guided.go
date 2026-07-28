package main

// Data class (given).
type PricingContext struct {
	baseFare float64
	availableDrivers int
	activeRideRequests int
	timeOfDay string
	weather string
}

type RideRequest struct {
	userId string
	pickup string
	dropoff string
	rideType string
}

// HINT: introduce an abstraction so new rules don't change existing code.

// HINT: start from what this must return, then work backwards to the state it needs.
func calculateSurge(ctx PricingContext) float64 {
	// TODO: write your solution
	return 0.0
}

// HINT: start from what this must return, then work backwards to the state it needs.
func calculateFare(req RideRequest, ctx PricingContext) float64 {
	// TODO: write your solution
	return 0.0
}
