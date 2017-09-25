#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using vi = vector<int>;
using vii = vector<ii>;

void process(int a, int b, int f, int k, int step, bool lastJourney, int& ans, int& gas) {
  if (a + (a-f) <= gas) {
    // Do nothing. Let the next step decide
    gas -= a;
    
  } else if (a <= gas) {
    // We can finish, but we can't come back to the gas station
    if (!lastJourney) {
      ans += 1;
      gas = b - (a-f);
    } else {
      gas -= a;
    }
    
  } else if (f <= gas) {
    // We can't reach the other end. Refill ASAP
    ans += 1;
    gas = b - (a-f);
    if (gas < 0) ans = -1;
    
  } else {
    ans = -1;
  }
}

int solve(int a, int b, int f, int k) {
  int ans = 0, way = 0, gas = b;
  
  for (int i = 0; i < k; ++i) {
    bool lastJourney = (i == k-1);
    
    process(a, b, (way == 1 ? a-f : f), k, i, lastJourney, ans, gas);
    
    if (ans == -1) break;
    
    way = 1 - way;
  }
  
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int a, b, f, k;
  while (cin >> a >> b >> f >> k) {
    cout << solve(a, b, f, k)  << endl;
  }
  
  return 0;
}
