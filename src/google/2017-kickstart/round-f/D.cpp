#include <iostream>
using namespace std;

const int kInf = 1000000000;
const int kMax = 10000;
int dp[kMax + 1];

void precalc() {
  dp[0] = 0;
  for (int c = 1; c <= kMax; ++c) {
    dp[c] = kInf;
    for (int i = 1; i*i <= c; ++i) {
      dp[c] = min(dp[c], 1 + dp[c-i*i]);
    }
  }
}

int solve() {
  int area;
  cin >> area;
  return dp[area];
}

int main() {
  precalc();
  
  int tc;
  cin >> tc;
  for (int i = 1; i <= tc; ++i) {
    cout << "Case #" << i << ": " << solve() << endl;
  }
  
  return 0;
}
