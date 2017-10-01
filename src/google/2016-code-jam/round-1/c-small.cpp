#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using int64 = long long;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using vi = vector<int>;
using vii = vector<ii>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int T;
  cin >> T;
  for (int caseno = 1; caseno <= T; ++caseno) {
    cout << "Case #" << caseno << ": ";
    
    int n;
    cin >> n;
    
    vector<string> fl, sl;
    for (int i = 0; i < n; ++i) {
      string a, b;
      cin >> a >> b;
      fl.push_back(a);
      sl.push_back(b);
    }
    
    int ans = 0;
    
    for (int mask = 1; mask < (1<<n); ++mask) {
      set<string> f, s;
      bool good = true;
      int m = 0;
      
      // Get base topics
      for (int i = 0; i < n; ++i) {
        if ((mask >> i) & 1) {
          f.insert(fl[i]);
          s.insert(sl[i]);
          m += 1;
        }
      }
      
      // Get derived topics
      for (int i = 0; i < n; ++i) {
        if (((mask >> i) & 1) == 0) {
          if (f.count(fl[i]) == 0) {
            good = false;
            break;
          }
          if (s.count(sl[i]) == 0) {
            good = false;
            break;
          }
        }
      }
      
      if (good) ans = max(ans, n - m);
    }
    
    cout << ans << endl;
  }
  
  return 0;
}
