#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using vi = vector<int>;
using ii = pair<int, int>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int tc;
  cin >> tc;
  assert(1 <= tc && tc <= 50);
  
  for (int cas = 1; cas <= tc; cas++) {
    int n;
    cin >> n;
    assert(1 <= n && n <= 100);
    
    vector<string> vec(n);
    for (int i = 0; i < n; ++i) {
      cin >> vec[i];
    }
    
    string s;
    cin >> s;
    
    const int m = s.size();
    assert(1 <= m && m <= 1000000);
    
    int ans = 0, next = inf;
    
    for (int i = 0; i  < m; i++) {
      int new_ending = inf;
      for (auto&& t : vec) {
        int len = t.size();
        
        if (i + len <= m) {
          bool ok = true;
          for (int a = 0; a < len; ++a) {
            if (t[a] != s[i + a]) {
              ok = false;
              break;
            }
          }
          if (ok) {
            new_ending = min(new_ending, i + len - 1);
          }
        }
      }
      next = min(new_ending, next);
      
      if (next == i) {
        //cerr << "Place $ at " << i << '\n';
        ans += 1;
        next = inf;
      }
    }
    
    cout << ans << '\n';
  }
  
  return 0;
}
