#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  while (true) {
    int n1, n2, d;
    cin >> n1 >> n2 >> d;
    if (n1 == 0) {
      break;
    }
    
    const int n = n1 + n2;
    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < d; ++i) {
      int x, y;
      cin >> x >> y;
      x -= 1, y -= 1;
      adj[x].push_back(y);
    }
    
    const int kFCD1 = 0, kFCD2 = 1;
    vector<int> visited(n, false), ans(2, 0);
    vector<vector<int>> dp(2, vector<int>(n));
    
    function<void(int)> dfs = [&](int u) {
      visited[u] = true;
      
      for (int v : adj[u]) {
        if (!visited[v]) {
          dfs(v);
        }
      }
      
      for (int k = 0; k < 2; ++k) {
        const int u_cd = (u < n1 ? kFCD1 : kFCD2);
        // Base case
        if (adj[u].size() == 0) {
          dp[k][u] = (u_cd == k ? 1 : 2);
        } else {
          // Recursive case
          int cd[2] = {0, 0};
          for (int v : adj[u]) {
            const int v_cd = (v < n1 ? kFCD1 : kFCD2);
            if (u_cd == v_cd) {
              cd[0] = max(cd[0], dp[k][v]);
            } else {
              cd[1] = max(cd[1], dp[k][v]);
            }
          }
          dp[k][u] = max(cd[0], cd[1] + 1);
        }
        // Update answer
        ans[k] = max(ans[k], dp[k][u]);
      }
    };
    
    for (int u = 0; u < n; ++u) {
      if (!visited[u]) {
        dfs(u);
      }
    }
    
    int result = min(ans[0], ans[1]) + 1;
    cout << result << '\n';
  }
  
  return 0;
}