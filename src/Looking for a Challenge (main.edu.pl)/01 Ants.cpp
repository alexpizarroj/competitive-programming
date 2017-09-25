#include <bits/stdc++.h>
using namespace std;

int main() {
  const long long kMult = 1600;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int tc;
  cin >> tc;
  
  for (int cas = 1; cas <= tc; ++cas) {
    int n;
    cin >> n;
    cin.ignore(1);
    
    int a = 0, k = 0;
    long long a1 = -1, k1 = 0, a2 = -1, k2 = 0;
    
    for (int i = 0; i < n / 2; ++i) {
      char ch;
      cin >> ch;
      int ch_value = ('0' <= ch && ch <= '9' ? ch - '0': ch - 'a' + 10);
      
      for (int j = 3; j >= 0; --j) {
        const int x = (ch_value >> j) & 1;
        const int b = (x == 1 ? 1 : -1);
         
        if (a1 == -1) {
          long long eps = ((6LL * n) - (9LL * a) - k) * kMult;
          assert(eps % (9 + b) == 0);
          eps /= (9 + b);
          if (0 <= eps && eps <= kMult) {
            a1 = kMult * a + eps;
            k1 = kMult* k + b * eps;
          }
        } else if (a2 == -1) {
          long long eps = (kMult * 12LL * n) - 9LL * (kMult * a - a1)
                           + (kMult * k - k1);
          assert(eps % (9 - b) == 0);
          eps /= (9 - b);
          if (0 <= eps && eps <= kMult) {
            a2 = kMult * a + eps;
            k2 = kMult * k + b * eps;
          }
        }
        
        a += 1, k += b;
      }
    }
    
    long long p = 3 * (a1 + a2) + k1 + k2, q = 4 * kMult;
    long long g = __gcd(p, q);
    p /= g, q /= g;
    
    cout << p << '/' << q << '\n';
  }
  
  return 0;
}
