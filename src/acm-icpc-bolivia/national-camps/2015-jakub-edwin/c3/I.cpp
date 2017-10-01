#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  
  vector<int> pos_to_val(n);
  for (int i = 0; i < n; i++) {
    cin >> pos_to_val[i];
    pos_to_val[i] -= 1;
  }
  
  vector<int> val_to_pos(n);
  for (int i = 0; i < n; i++) {
    val_to_pos[pos_to_val[i]] = i;
  }
  
  vector<pair<int, int>> ans;
  for (int i = 0; i < n; i++) {
    while (pos_to_val[i] != i) {
      int a = i;
      int b = val_to_pos[i];
      
      int sz = b - a + 1;
      if (sz % 2 != 0) {
        sz -= 1;
        a += 1;
      }
      
      for (int j = 0; j < sz / 2; j++) {
        int x = a + j;
        int y = x + sz / 2;
        int x_val = pos_to_val[y];
        int y_val = pos_to_val[x];
        
        pos_to_val[x] = x_val;
        val_to_pos[x_val] = x;
        pos_to_val[y] = y_val;
        val_to_pos[y_val] = y;
      }
      
      ans.emplace_back(a + 1, b + 1);
    }
  }
  
  cout << ans.size() << '\n';
  for (const auto& p : ans) {
    cout << p.first << " " << p.second << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int tc;
  cin >> tc;
  
  for (int i = 0; i < tc; i++) {
    solve();
  }
  
  return 0;
}
