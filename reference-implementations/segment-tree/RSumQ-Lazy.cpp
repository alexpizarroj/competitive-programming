#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
  using TValue = long long;                          // type of node values
  int n;                                             // size of the array covered by the tree
  vector<TValue> st;                                 // value by node id
  vector<TValue> lazy;                               // lazy value by node id

  int l(int p) { return  p<<1; }                     // go to left child  (2*p)
  int r(int p) { return (p<<1)+1; }                  // go to right child (2*p+1)

  // ==================================
  // START: Function definition (RSumQ)
  // ==================================

  // A value that signals an unset lazy flag
  const TValue unset = -1;
  // A neutral value for `conquer`, such that `conquer(x, neutral)` and `conquer(neutral, x)` return `x`
  const TValue neutral = 0;

  // Take two node values and return their combined result
  TValue conquer(TValue a, TValue b) { return a + b; }

  // Propagate lazy value for node `p`
  void propagate(int p, int L, int R) {
    if (lazy[p] == unset) return;

    // Update node value from lazy value
    st[p] += lazy[p] * (R - L + 1);

    // Propagate lazy value downward if `p` isn't a leaf
    if (L != R) {
      update_lazy(l(p), lazy[p]);
      update_lazy(r(p), lazy[p]);
    }

    // Unset lazy value
    lazy[p] = unset;
  }

  // Update lazy value for node `p` with the given value
  void update_lazy(int p, TValue val) {
    if (lazy[p] == unset) {
      lazy[p] = val;
    } else {
      lazy[p] += val;
    }
  }

  // ================================
  // END: Function definition (RSumQ)
  // ================================

  void build(int p, int L, int R, const vector<TValue> &A) {  // O(n)
    if (L == R) {
      st[p] = A[L];
    } else {
      int lc = l(p), rc = r(p);
      int m = (L+R)/2;
      build(lc, L  , m, A);
      build(rc, m+1, R, A);
      st[p] = conquer(st[lc], st[rc]);
    }
  }

  TValue query(int p, int L, int R, int i, int j) {  // O(log n)
    propagate(p, L, R);                              // lazy propagation
    if (i > j) return neutral;                       // infeasible
    // invariant: segment [i..j] is included in or equal to segment [L..R] of node `p`
    if (i == L && j == R) {
      return st[p];
    } else {
      int m = (L+R)/2;
      TValue lval = query(l(p), L  , m, i          , min(m, j));
      TValue rval = query(r(p), m+1, R, max(i, m+1), j        );
      return conquer(lval, rval);
    }
  }

  void update(int p, int L, int R, int i, int j, TValue val) {  // O(log n)
    propagate(p, L, R);                              // lazy propagation
    if (i > j) return;                               // infeasible
    // invariant: segment [i..j] is included in or equal to segment [L..R] of node `p`
    if (i == L && j == R) {
      update_lazy(p, val);
      propagate(p, L, R);
    } else {
      int lc = l(p), rc = r(p);
      int m = (L+R)/2;
      update(lc, L  , m, i,           min(m, j), val);
      update(rc, m+1, R, max(i, m+1), j,         val);
      st[p] = conquer(st[lc], st[rc]);
    }
  }

public:
  SegmentTree(int size) {
      // smallest power of two, greather than or equal to `size`
      int n2 = 1;
      while (n2 < size) n2 *= 2;

      n = size;
      st = vector<TValue>(2 * n2, neutral);
      lazy = vector<TValue>(2 * n2, unset);
  }

  SegmentTree(const vector<TValue> &initialA) : SegmentTree((int)initialA.size()) {
    build(1, 0, n-1, initialA);
  }

  TValue query(int i, int j) {
    return query(1, 0, n-1, i, j);
  }

  void update(int i, int j, TValue val) {
    update(1, 0, n-1, i, j, val);
  }
};
