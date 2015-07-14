#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  unsigned int x;
  while (cin >> x) {
    int msb = 31;
    for (; !((x >> msb) & 1); msb -= 1);
    
    unsigned int y = 0;
    for (int i = 0; i <= msb; i++) {
      if ((x >> i) & 1) {
        y |= (1 << (msb - i));
      }
    }
    
    cout << y << '\n';
  }
  
  return 0;
}
