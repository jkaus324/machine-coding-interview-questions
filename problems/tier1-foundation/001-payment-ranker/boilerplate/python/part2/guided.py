# Data class (given).
class PaymentMethod:
    def __init__(self, name, cashbackRate, transactionFee, usageCount, easyRefundEligible=False):
        self.name = name
        self.cashbackRate = cashbackRate
        self.transactionFee = transactionFee
        self.usageCount = usageCount
        self.easyRefundEligible = easyRefundEligible

# HINT: introduce an abstraction so new variants don't change existing code.

# HINT: start from what this must return, then work backwards to the state it needs.
def rank_by_rewards(methods):
    # TODO: write your solution
    return methods

# HINT: start from what this must return, then work backwards to the state it needs.
def rank_by_low_fee(methods):
    # TODO: write your solution
    return methods

# HINT: start from what this must return, then work backwards to the state it needs.
def rank_by_trust(methods):
    # TODO: write your solution
    return methods

# HINT: you're handed a list of interchangeable behaviours — call them all through one interface.
def rank_composite(methods, criteria):
    # TODO: write your solution
    return methods
