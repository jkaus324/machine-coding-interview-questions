package main

// Data class (given).
type PaymentMethod struct {
	name string
	cashbackRate float64
	transactionFee float64
	usageCount int
	easyRefundEligible bool
}

// RankingStrategy — implement this interface with your own strategy types.
type RankingStrategy interface {
	// TODO: define the method(s) your strategies share.
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

// HINT: you're handed a list of interchangeable behaviours — call them all through one interface.
func rank_composite(methods []PaymentMethod, criteria []RankingStrategy) []PaymentMethod {
	// TODO: write your solution
	return methods
}

// HINT: a flag that changes behaviour is its own concern — keep it a separate piece you can chain.
func rank_with_refund_filter(methods []PaymentMethod, preferEasyRefund bool) []PaymentMethod {
	// TODO: write your solution
	return methods
}
