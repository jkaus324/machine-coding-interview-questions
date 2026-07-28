// Data class (given).
class PaymentMethod {
  constructor(name, cashbackRate, transactionFee, usageCount, easyRefundEligible = false) {
    this.name = name;
    this.cashbackRate = cashbackRate;
    this.transactionFee = transactionFee;
    this.usageCount = usageCount;
    this.easyRefundEligible = easyRefundEligible;
  }
}

// HINT: introduce an abstraction so new rules don't change existing code.

// HINT: start from what this must return, then work backwards to the state it needs.
function rank_by_rewards(methods) {
  // TODO: write your solution
  return methods;
}

// HINT: start from what this must return, then work backwards to the state it needs.
function rank_by_low_fee(methods) {
  // TODO: write your solution
  return methods;
}

// HINT: start from what this must return, then work backwards to the state it needs.
function rank_by_trust(methods) {
  // TODO: write your solution
  return methods;
}

// ── Export everything the test runner needs (do not remove) ──
// If you add classes (e.g. strategy subclasses), add them here too.
module.exports = { PaymentMethod, rank_by_rewards, rank_by_low_fee, rank_by_trust };
