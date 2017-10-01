#include <iostream>
using namespace std;

int f(int x) {
  if (x == 0) return -1;
    
  const int target = 1023;
  int i = 0, cur = 0, y = 0;
  
  do {
    y += x;
    i += 1;
    
    int z = y;
    do {
      int d = (z % 10);
      cur |= (1 << d);
      z /= 10;
    } while (z > 0);
  } while (cur != target);
  
  return y;
}

int main() {
  int tc;
  cin >> tc;
  
  for (int i = 1; i <= tc; ++i) {
    cout << "Case #" << i << ": ";
    
    int x;
    cin >> x;
    
    int fx = f(x);
    if (fx == -1) {
      cout << "INSOMNIA\n";
    } else {
      cout << fx << '\n';
    }
  }
  
  return 0;
}
