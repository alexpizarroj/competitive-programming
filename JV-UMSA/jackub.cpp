#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int tc;
  cin >> tc;
  
  for (int t = 1; t <= tc; t++) {
    string key, word;
    cin >> key >> word;
    
    vector<int> pos(256, 0);
    for (int i = 0; i < (int)key.size(); i++) {
      pos[(int)key[i]] = i;
    }
    
    int ans = 0;
    for (int i = 1; i < (int)word.size(); i++) {
      int a = pos[(int)word[i - 1]];
      int b = pos[(int)word[i]];
      ans += abs(a - b);
    }
    cout << ans << '\n';
  }
  
  return 0;
}
