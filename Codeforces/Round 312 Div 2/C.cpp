#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using ii = pair<int, int>;
using vi = vector<int>;
using i64 = long long;

bool is_power_of_two(unsigned int x) {
  return ((x & (x - 1)) == 0);
}

int equalize(int src, int dst) {
  int ans = inf, penalty = 0;
  
  do {
    if (dst % src == 0 && is_power_of_two(dst / src)) {
      int p = dst / src, cand = penalty;
      for (int y = src; y != dst; y <<= 1, ++cand);
      if (cand < ans) {
        ans = cand;
      }
    }
    penalty += 1;
    src /= 2;
  } while (src > 0);
  
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  while (cin >> n) {
    vi vec(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
      cin >> vec[i];
      mx = max(mx, vec[i]);
    }
    
    set<int> ma;
    int a = vec[0];
    do {
      ma.insert(a);

      int b = a * 2;
      while (b <= mx) {
        ma.insert(b);
        b *= 2;
      }
      a /= 2;
      
    } while (a > 0);
    
    int ans = inf;
    for (int meet : ma) {
      int cand = 0;
      bool ok = true;
      
      for (int i = 0; i < n; i++) {
        int ret = equalize(vec[i], meet);
        if (ret == inf) {
          ok = false;
          break;
        }
        cand += ret;
      }
      
      if (ok && cand < ans) {
        ans = cand;
      }
    }
    
    cout << ans << '\n';
  }
  
  return 0;
}