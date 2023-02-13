#include <bits/stdc++.h>
using namespace std;

class StNode {
private:
  using TValue = long long;  // type of node values

  // ==================================
  // START: Function definition (RMinQ)
  // ==================================

  // A neutral value for `conquer`, such that `conquer(x, neutral)` and `conquer(neutral, x)` return `x`
  const TValue neutral = numeric_limits<TValue>::max();

  // Take two node values and return their combined result
  TValue conquer(TValue a, TValue b) { return min(a, b); }

  // ================================
  // END: Function definition (RMinQ)
  // ================================

  int l, r;
  shared_ptr<StNode> lc = nullptr;
  shared_ptr<StNode> rc = nullptr;
  TValue val = neutral;

  void conquer_children() { val = conquer(lc->val, rc->val); }

  void build(const vector<TValue>* A = nullptr) {  // O(n)
    if (l == r) {  // Is this a leaf?
      val = A ? (*A)[l] : neutral;
    } else {
      int m = (l + r) / 2;
      lc = make_shared<StNode>(l, m);
      rc = make_shared<StNode>(m+1, r);
      lc->build(A);
      rc->build(A);
      conquer_children();
    }
  }

public:
  StNode(int l_, int r_) : l(l_), r(r_) { }

  StNode(int size_) : l(0), r(size_-1) { build(); }

  StNode(const vector<TValue>& initialA) : l(0), r((int)initialA.size()) { build(&initialA); }

  int size() { return r - l + 1; }

  TValue query(int i, int j) {  // O(log n)
    if (i > j) return neutral;  // Infeasible
    // Invariant: segment [i..j] is included in or equal to segment [l..r] of this node
    if (i == l && j == r) {
      return val;
    } else {
      int m = (l + r) / 2;
      TValue lval = lc->query(i          , min(m, j));
      TValue rval = rc->query(max(i, m+1), j        );
      return conquer(lval, rval);
    }
  }

  void update(int i, TValue val_) {  // O(log n)
    // Invariant: index `i` is included segment [l..r] of this node
    if (l == r) {  // Is this a leaf?
      val = val_;
    } else {
      int m = (l + r) / 2;
      if (i <= m) {
        lc->update(i, val_);
      } else {
        rc->update(i, val_);
      }
      conquer_children();
    }
  }
};
