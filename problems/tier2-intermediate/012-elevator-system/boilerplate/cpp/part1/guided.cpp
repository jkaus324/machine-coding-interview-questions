#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


// Data class (given).
struct ElevOp {
    string kind;
    string s1;
    int i1;
    int i2;
    ElevOp(const string& kind_, const string& s1_ = "", int i1_ = 0, int i2_ = 0)
      : kind(kind_), s1(s1_), i1(i1_), i2(i2_) {}
};

// HINT: introduce an abstraction so new variants don't change existing code.
// HINT: keep each piece small — one responsibility per class.

// HINT: start from what this must return, then work backwards to the state it needs.
vector<string> elevator_simulate(vector<ElevOp> ops) {
    // TODO: write your solution
    return {};
}
