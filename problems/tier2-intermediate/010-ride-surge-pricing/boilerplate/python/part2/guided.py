# Data class (given).
class PricingContext:
    def __init__(self, baseFare, availableDrivers, activeRideRequests, timeOfDay, weather):
        self.baseFare = baseFare
        self.availableDrivers = availableDrivers
        self.activeRideRequests = activeRideRequests
        self.timeOfDay = timeOfDay
        self.weather = weather

class RideRequest:
    def __init__(self, userId, pickup, dropoff, rideType):
        self.userId = userId
        self.pickup = pickup
        self.dropoff = dropoff
        self.rideType = rideType

# HINT: introduce an abstraction so new variants don't change existing code.

# HINT: start from what this must return, then work backwards to the state it needs.
def calculateSurge(ctx):
    # TODO: write your solution
    return None

# HINT: start from what this must return, then work backwards to the state it needs.
def calculateFare(req, ctx):
    # TODO: write your solution
    return None
