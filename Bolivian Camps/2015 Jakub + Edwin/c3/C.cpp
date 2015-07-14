#include <bits/stdc++.h>
using namespace std;

void solve() {
  using i64 = long long;
  
  int n;
  cin >> n;
  
  vector<long long> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
  }
  
  map<i64, int> lst[2];
  lst[0][vec[0]] = 0;
  
  long long ans = vec[0];
  int cur = 1;
  for (int j = 1; j < n; j++) {
    lst[cur].clear();
    lst[cur][vec[j]] = j;
    for (auto&& p : lst[1 - cur]) {
      i64 g = __gcd(p.first, vec[j]);
      int s = p.second;
      if (lst[cur].count(g) > 0) {
        int cur_s = lst[cur][g];
        if (cur_s > s) {
          lst[cur][g] = s;
        }
      } else {
        lst[cur][g] = s;
      }
    }
    
    for (auto&& p : lst[cur]) {
      i64 cand = (j - p.second + 1) * p.first;
      if (cand > ans) {
        ans = cand;
      }
    }
    
    cur = 1 - cur;
  }
  
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int tc;
  cin >> tc;
  
  for (int i = 0; i < tc; ++i) {
    solve();
  }
  
  return 0;
}
