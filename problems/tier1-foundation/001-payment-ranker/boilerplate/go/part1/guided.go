package main

// Data class (given).
type PaymentMethod struct {
	name string
	cashbackRate float64
	transactionFee float64
	usageCount int
	easyRefundEligible bool
}

// HINT: introduce an abstraction so new rules don't change existing code.

// HINT: start from what this must return, then work backwards to the state it needs.
func rank_by_rewards(methods []PaymentMethod) []PaymentMethod {
	// TODO: write your solution
	return methods
}

// HINT: start from what this must return, then work backwards to the state it needs.
func rank_by_low_fee(methods []PaymentMethod) []PaymentMethod {
	// TODO: write your solution
	return methods
}

// HINT: start from what this must return, then work backwards to the state it needs.
func rank_by_trust(methods []PaymentMethod) []PaymentMethod {
	// TODO: write your solution
	return methods
}
