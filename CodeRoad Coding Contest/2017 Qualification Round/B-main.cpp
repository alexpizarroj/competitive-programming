#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  
  int a, b;
  while (cin >> a >> b) {
    vector<bool> good(b+1, 1);
    
    long long fib1=1, fib2=2;
    while (fib2 <= b) {
      if (good[fib2]) {
        for (int i=fib2; i <= b; i+=fib2) {
          good[i] = false;
        }
      }
      swap(fib1, fib2);
      fib2 = fib1 + fib2;
    }
    
    int ans = 0;
    for (int i = a; i <= b; ++i) ans += (good[i] ? 1 : 0);
    cout << ans << endl;
  }
  return 0;
}
