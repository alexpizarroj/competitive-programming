#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;
  
  int a = 0, b = 2000000007, ans = -1;
  for (int i = 0; i < n; i++) {
    int le, ri;
    cin >> le >> ri;
    
    int y = le + ri;
    if (y < a) {
      a = 0;
      b = y;
    } else if (y <= b) {
      b = y - a;
      a = 0;
      ans += 1;
    } else {
      b = y - b;
      a = y - a;
      swap(a, b);
      ans += 1;
    }
  }
  cout << ans << '\n';
  
  return 0;
}