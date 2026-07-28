#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


// Data class (given).
struct PaymentMethod {
    string name;
    double cashbackRate;
    double transactionFee;
    int usageCount;
    bool easyRefundEligible;
    PaymentMethod(const string& name_, double cashbackRate_, double transactionFee_, int usageCount_, bool easyRefundEligible_ = false)
      : name(name_), cashbackRate(cashbackRate_), transactionFee(transactionFee_), usageCount(usageCount_), easyRefundEligible(easyRefundEligible_) {}
};

// HINT: introduce an abstraction so new variants don't change existing code.
// HINT: keep each piece small — one responsibility per class.

// HINT: start from what this must return, then work backwards to the state it needs.
vector<PaymentMethod> rank_by_rewards(vector<PaymentMethod> methods) {
    // TODO: write your solution
    return methods;
}

// HINT: start from what this must return, then work backwards to the state it needs.
vector<PaymentMethod> rank_by_low_fee(vector<PaymentMethod> methods) {
    // TODO: write your solution
    return methods;
}

// HINT: start from what this must return, then work backwards to the state it needs.
vector<PaymentMethod> rank_by_trust(vector<PaymentMethod> methods) {
    // TODO: write your solution
    return methods;
}
