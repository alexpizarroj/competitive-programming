#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  int tc;
  cin >> tc;
  
  for (int tcase = 1; tcase <= tc; ++tcase) {
    cout << "Case #" << tcase << ": ";
    
    string s;
    cin >> s;
    
    int ans = 0, m = 1;
    for (int i = (int)s.size() - 1; i >= 0; --i) {
      int val = (s[i] == '+' ? 1 : -1);
      if (m * val == -1) {
        ans += 1;
        m *= -1;
      }
    }
    
    cout << ans << '\n';
  }
  
  return 0;
}
