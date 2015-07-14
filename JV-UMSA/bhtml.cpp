#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  const int up = 0, down = 1;
  stack<int> tags;
  
  string s;
  while (getline(cin, s)) {
    string ans = "";
    for (int i = 0; i < (int)s.size(); i++) {
      // Process tags
      if (s[i] == '<') {
        if (s[i + 1] == '/') {
          i += (s[i + 2] == 'U' ? 4 : 6);
          tags.pop();
        } else {
          tags.push(s[i + 1] == 'U' ? up : down);
          i += (s[i + 1] == 'U' ? 3 : 5);
        }
        continue;
      }
      // Process text
      char c = s[i];
      if (!tags.empty()) {
        c = (tags.top() == up ? toupper(c) : tolower(c));
      }
      ans.push_back(c);
    }
    
    cout << ans << '\n';
  }
  
  return 0;
}
