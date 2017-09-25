#include <iostream>
using namespace std;

using int64 = long long;

int main() {
  int tc;
  cin >> tc;
  
  for (int tcase = 1; tcase <= tc; ++tcase) {
    cout << "Case #" << tcase << ":";
    
    int k, c, s;
    cin >> k >> c >> s;
    
    if (k > c * s) {
      cout << " IMPOSSIBLE\n";
      continue;
    }
    
    int next = 1;
    
    while (next <= k) {
      const int n_we_will_take = min(k - next + 1, c);
      
      int64 x = next;
      for (int i = 1; i < n_we_will_take; ++i) {
          x = (x - 1) * k + (next + i);
      }
      cout << " " << x;
      
      next += n_we_will_take;
    }
    
    cout << "\n";
  }
  
  return 0;
}
