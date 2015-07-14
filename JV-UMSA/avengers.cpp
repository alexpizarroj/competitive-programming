#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int m;
  while (cin >> m) {
    vector<string> av;
    
    for (int i = 0; i < m; i++) {
      int n;
      cin >> n;
      
      for (int j = 0; j < n; j++) {
        string s;
        cin >> s;
        av.push_back(s);
      }
    }
    
    string hated;
    cin >> hated;
    
    sort(begin(av), end(av));
    av.erase(unique(begin(av), end(av)), end(av));
    
    auto it = lower_bound(begin(av), end(av), hated);
    int ans = distance(begin(av), it);
    if (it != end(av) && (*it) != hated) {
      ans -= 1;
    }
    
    cout << ans << '\n';
  }
  
  return 0;
}
