#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  string s;
  while (cin >> s) {
    string ans = s;
    
    int n = s.size();
    s = s + s;
    
    for (int i = 0; i < n; i++) {
      // Option 1
      string a = s.substr(i, n);
      if (a < ans) {
        ans = a;
      }
      // Option 2
      reverse(begin(a), end(a));
      if (a < ans) {
        ans = a;
      }
    }
    
    cout << ans << '\n';
  }
  
  return 0;
}