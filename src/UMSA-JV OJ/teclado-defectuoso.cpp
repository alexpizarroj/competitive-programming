#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  string txt;
  while (getline(cin, txt)) {
    list<char> res;
    list<char>::iterator it = res.begin();
    
    for (char c : txt) {
      if (c == '[') {
        it = res.begin();
      } else if (c == ']') {
        it = res.end();
      } else {
        it = res.insert(it, c);
        ++it;
      }
    }
    
    for (auto&& c : res) {
      cout << c;
    }
    cout << '\n';
  }
  
  return 0;
}
