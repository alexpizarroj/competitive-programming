#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  vector<string> seen;
  char buffer[256];
  int len = 0;
  
  while (true) {
    char c;
    bool res = (bool)(cin.get(c));
    
    if (res && isalpha(c)) {
      buffer[len++] = tolower(c);
    } else {
      if (len > 0) {
        buffer[len] = 0;
        seen.push_back(string(buffer));
        len = 0;
      }
      if (res == false) {
        break;
      }
    }
  }
  
  sort(begin(seen), end(seen));
  seen.erase(unique(begin(seen), end(seen)), end(seen));
  for (auto&& s : seen) {
    cout << s << '\n';
  }
  
  return 0;
}
