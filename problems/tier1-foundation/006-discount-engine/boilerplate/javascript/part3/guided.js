// Data class (given).
class CartItem {
  constructor(name, price, quantity, category = "") {
    this.name = name;
    this.price = price;
    this.quantity = quantity;
    this.category = category;
  }
}

// HINT: introduce an abstraction so new rules don't change existing code.

// HINT: start from what this must return, then work backwards to the state it needs.
function apply_percentage_discount(cart, percentage) {
  // TODO: write your solution
  return null;
}

// HINT: start from what this must return, then work backwards to the state it needs.
function apply_flat_discount(cart, amount) {
  // TODO: write your solution
  return null;
}

// HINT: start from what this must return, then work backwards to the state it needs.
function apply_bogo(cart, buyCount, freeCount) {
  // TODO: write your solution
  return null;
}

// HINT: start from what this must return, then work backwards to the state it needs.
function apply_percentage_with_eligibility(cart, percentage, minCartValue, requireFirstTimeUser, isFirstTimeUser, eligibleCategory) {
  // TODO: write your solution
  return null;
}

// ── Export everything the test runner needs (do not remove) ──
// If you add classes (e.g. strategy subclasses), add them here too.
module.exports = { CartItem, apply_percentage_discount, apply_flat_discount, apply_bogo, apply_percentage_with_eligibility };
