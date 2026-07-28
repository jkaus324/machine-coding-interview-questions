#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


// Data class (given).
struct CartItem {
    string name;
    double price;
    int quantity;
    string category;
    CartItem(const string& name_, double price_, int quantity_, const string& category_ = "")
      : name(name_), price(price_), quantity(quantity_), category(category_) {}
};

// HINT: introduce an abstraction so new variants don't change existing code.
// HINT: keep each piece small — one responsibility per class.

// HINT: start from what this must return, then work backwards to the state it needs.
double apply_percentage_discount(vector<CartItem> cart, double percentage) {
    // TODO: write your solution
    return {};
}

// HINT: start from what this must return, then work backwards to the state it needs.
double apply_flat_discount(vector<CartItem> cart, double amount) {
    // TODO: write your solution
    return {};
}

// HINT: start from what this must return, then work backwards to the state it needs.
double apply_bogo(vector<CartItem> cart, int buyCount, int freeCount) {
    // TODO: write your solution
    return {};
}
