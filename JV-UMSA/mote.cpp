#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int T;
  cin >> T;
  
  for (int tc = 1; tc <= T; tc++) {
    int n;
    cin >> n;
    
    vector<string> name(n);
    for (int i = 0; i < n; i++) {
      cin >> name[i];
    }
  
    string ans = "";
    unsigned int len = 0;
    while (true) {
      bool ok = true;
      for (int i = 1; i < n; i++) {
        if (!((len < name[i - 1].size()) && (len < name[i].size()) &&
              (name[i - 1][len] == name[i][len]))) {
          ok = false;
          break;
        }
      }
      
      if (ok) {
        ans.push_back(name[0][len]);
        len += 1;
      } else {
        break;
      }
    }
    
    cout << (len == 0 ? "meh" : ans) << '\n';
  }
  
  return 0;
}
