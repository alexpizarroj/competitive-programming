#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc;
  cin >> tc;
  
  for (int t = 1; t <= tc; t++) {
    int m, c;
    cin >> m >> c;
    
    int min_cost = 0;
    vector<vector<int>> flavors(c);
    for (int i = 0; i < c; i++) {
      int k;
      cin >> k;
      
      flavors[i].resize(k);
      for (int j = 0; j < k; j++) {
        cin >> flavors[i][j];
      }
      sort(begin(flavors[i]), end(flavors[i]));
      
      min_cost += flavors[i][0];
    }
    
    if (m >= min_cost) {
      // Get the answer
      vector<vector<bool>> dp(c + 1, vector<bool>(m + 1, false));
      dp[0][m] = true;
      for (int i = 1; i <= c; i++) for (int p = 0; p <= m; p++) {
        // Current state is dp[i][p]. Can it be reached?
        for (int ch : flavors[i - 1]) {
          int prev_m = p + ch;
          if (prev_m <= m && dp[i - 1][prev_m]) {
            dp[i][p] = true;
            break;
          }
        }
      }
      // Output
      int ans = 0;
      for (; !dp[c][ans] && ans <= m; ++ans);
      ans = m - ans;
    
      cout << ans << '\n';
    } else {
      cout << "No es posible\n";
    }
  }
  
  return 0;
}
