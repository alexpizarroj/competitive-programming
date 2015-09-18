#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using ii = pair<int, int>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int tc;
  cin >> tc;
  
  for (int cas = 1; cas <= tc; ++cas) {
    int n;
    cin >> n;
    
    ii mn(inf, inf), mx(-inf, -inf);
    vector<ii> vec(n);
    
    for (int i = 0; i < n; ++i) {
      cin >> vec[i].first >> vec[i].second;
      
      mn.first = min(vec[i].first, mn.first);
      mn.second = min(vec[i].second, mn.second);
      mx.first = max(vec[i].first, mx.first);
      mx.second = max(vec[i].second, mx.second);
    }
    
    int ans = 2;
    
    ii p[4] = {mn, ii(mn.first, mx.second), mx, ii(mx.first, mn.second)};
    string face[4] = {"NE", "SE", "SW", "NW"};
    for (int i = 0; i < 4; ++i) {
      int idx = find(begin(vec), end(vec), p[i]) - begin(vec);
      if (idx != n) {
        ans = 1;
        cout << ans << '\n' << (idx + 1) << " " << face[i] << '\n';
        break;
      }
    }
    
    if (ans == 2) {
      cout << ans << '\n';
      int a[2] = {0, 0}; string outface[2];
      
      for (int i = 0; i < n; ++i) {
        if (vec[i].first == mn.first) a[0] = i;
        else if (vec[i].first == mx.first) a[1] = i;
      }
      
      if (vec[a[0]].second <= vec[a[1]].second) {
        outface[0] = "NE";
        outface[1] = "SW";
      } else {
        outface[0] = "SE";
        outface[1] = "NW";
      }
      
      cout << (a[0] + 1) << " " << outface[0] << '\n';
      cout << (a[1] + 1) << " " << outface[1] << '\n';
    }
  }
  
  return 0;
}
