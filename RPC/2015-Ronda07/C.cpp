#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
  while (b != 0) {
    long long c = a % b;
    a = b;
    b = c;
  }
  return a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int tc;
  cin >> tc;
  
  for (int caso = 1; caso <= tc; ++caso) {
    int n;
    cin >> n;
    
    int cur = 0;
    long long ans = 0;
    map<long long, int> gcds[2];
    
    for (int i = 0; i < n; ++i) {
      long long x;
      cin >> x;
      
      gcds[cur].clear();
      
      gcds[cur].insert(make_pair(x, i));
      ans = max(ans, x);
      
      map<long long, int>::iterator it;
      for (it = gcds[1 - cur].begin(); it != gcds[1 - cur].end(); ++it) {
        const pair<long long, int>& p = (*it);
        long long g = gcd(x, p.first);
        
        if (gcds[cur].count(g) == 0) {
          gcds[cur].insert(make_pair(g, p.second));
        } else {
          if (p.second < gcds[cur][g]) {
            gcds[cur][g] = p.second;
          }
        }
        
        long long cand = g * (i - gcds[cur][g] + 1);
        ans = max(ans, cand);
      }
      
      cur = 1 - cur;
    }
    
    cout << ans << '\n';
  }
  
  return 0;
}
