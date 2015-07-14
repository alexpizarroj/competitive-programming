#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using vi = vector<int>;
using i64 = long long;

int f(int cur, const vector<vector<ii>>& vec) {
  int res = 0, pos[2] = {0, 0};
  while (pos[cur] < (int)vec[cur].size()) {
    res += vec[cur][pos[cur]].second;
    pos[cur] += 1;
    cur = 1 - cur;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  while (cin >> n) {
    vector<vector<ii>> vec(2, vector<ii>());
    for (int i = 0; i < n; i++) {
      ii p;
      cin >> p.first >> p.second;
      if (p.first < 0) {
        vec[0].push_back(p);
      } else {
        vec[1].push_back(p);
      }
    }
    
    sort(begin(vec[0]), end(vec[0]), greater<ii>());
    sort(begin(vec[1]), end(vec[1]));
    
    int ans = max(f(0, vec), f(1, vec));
    cout << ans << endl;
  }
  
  return 0;
}