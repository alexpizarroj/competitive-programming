#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  while (cin >> n) {
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
      cin >> vec[i];
    }
    
    sort(vec.begin(), vec.end());
    
    vector<int> mx(n, 0);
    mx[0] = vec[0];
    for (int i = 1; i < n; ++i) {
      mx[i] = max(mx[i - 1], vec[i]);
    }
    
    int ans = 1000000007;
    for (int i = 0; i <= n; ++i) {
      int cand = i + (i < n ? mx[n - i - 1] : 0);
      ans = min(ans, cand);
    }
    
    cout << ans << '\n';
  }
  
  return 0;
}
