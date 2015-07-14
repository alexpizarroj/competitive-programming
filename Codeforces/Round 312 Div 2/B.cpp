#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using vi = vector<int>;
using i64 = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  while (cin >> n) {
    map<int, pair<int, ii>> f;
    int max_freq = 1;
    
    for (int i = 0 ; i < n; i++) {
      int x;
      cin >> x;
      if (f.count(x) == 0) {
        f[x] = make_pair(1, make_pair(i, i));
      } else {
        auto p = f[x];
        p.first += 1;
        p.second.second = i;
        f[x] = p;
        
        if (p.first > max_freq) {
          max_freq = p.first;
        }
      }
    }
    
    int a = 0,  b = 1000000007;
    for (auto&& pkv : f) {
      auto p = pkv.second;
      if (p.first != max_freq) {
        continue;
      }
      
      int len1 = b - a + 1;
      int len2 = p.second.second - p.second.first + 1;
      if (len2 < len1) {
        a = p.second.first;
        b = p.second.second;
      }
    }
    
    cout << (1 + a) << " " << (1 + b) << '\n';
  }
  
  return 0;
}