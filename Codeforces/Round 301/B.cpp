#include <bits/stdc++.h>
#define bend(vec) begin(vec), end(vec)
using namespace std;

vector<int> solve(int n, int k, int p, int x, int y) {
  static const vector<int> kCantSolve{-1};
  
  // Tests that were taken before hand
  vector<int> tests(k);
  int current_score = 0;
  for(int &item : tests) {
    cin >> item;
    current_score += item;
  }
  
  // Bound too tight?
  int min_score = current_score + (n - k);
  if (min_score > x) {
    return kCantSolve;
  }
  
  // Let's try
  const int kPerHalf = (n - 1) / 2;
  for(int med = y; med <= p; med++) {
    // Median data
    int le = 0, eq = 0, gr = 0;
    for(int t : tests) {
      if (t < med) {
        le += 1;
      } else if (t == med) {
        eq += 1;
      } else {
        gr += 1;
      }
    }
    
    // This must hold for 'med' to be a viable median
    if (le > kPerHalf || gr > kPerHalf) {
      continue;
    }
    
    int score = current_score;
    vector<int> ans;
    
    // Adjust the values if we had/didn't have a median before hand
    if (eq > 0) {
      eq -= 1;
    } else {
      ans.push_back(med);
      score += med;
    }
    
    // Distribute median values greedily
    if (eq > 0) {
      int delta = min(kPerHalf - gr, eq);
      gr += delta;
      eq -= delta;
      if (eq > 0) {
        le += eq;
        eq = 0;
      }
    }
    assert(gr <= kPerHalf && le <= kPerHalf && eq == 0);
    
    // Get the final score
    score += (kPerHalf - le) * 1 + (kPerHalf - gr) * med;
    if (score <= x) {
      for(int i = 0; i < (kPerHalf - le); i++) {
        ans.push_back(1);
      }
      for(int i = 0; i < (kPerHalf - gr); i++) {
        ans.push_back(med);
      }
      return ans;
    }
  }
  
  return kCantSolve;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, k, p, x, y;
  while (cin >> n >> k >> p >> x >> y) {
    for(int item : solve(n, k, p, x, y)) {
      cout << item << " ";
    }
    cout << '\n';
  }
  
  return 0;
}
