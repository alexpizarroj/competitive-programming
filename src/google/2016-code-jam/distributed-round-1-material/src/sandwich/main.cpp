#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include "sandwich.h"
#include "message.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

int main() {
  if (MyNodeId() == 0) {
    int n = GetN();
    
    vll lsum(n + 1), rsum(n + 1);
    for (int i = 0; i < n; ++i) {
      lsum[i] = (i > 0 ? lsum[i-1] : 0) + GetTaste(i);
    }
    for (int i = n - 1; i >= 0; --i) {
      rsum[i] = (i < n - 1 ? rsum[i+1] : 0) + GetTaste(i);
    }
    
    long long ans = 0;
    for (int i = -1; i < n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        ans = max(ans, (i > -1 ? lsum[i] : 0) + (j < n ? rsum[j] : 0));
      }
    }
    
    cout << ans << endl;
  }
  return 0;
}
