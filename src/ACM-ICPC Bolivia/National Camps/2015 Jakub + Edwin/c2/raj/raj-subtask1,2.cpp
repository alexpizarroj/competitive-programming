#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  if (!(n <= 1000 && m <= 100000)) {
    return 0;
  }

  // Graph data
  vector<vector<int>> adj(n, vector<int>()), inc(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a -= 1, b -= 1;
    adj[a].push_back(b);
    inc[b].push_back(a);
  }

  // Get a DP-friendly vertex processing order
  vector<int> topo;
  vector<bool> added(n, false);
  function<void(int)> dfs = [&](int u) {
    if (added[u]) {
      return;
    }

    for (int v : adj[u]) {
      dfs(v);
    }

    added[u] = true;
    topo.push_back(u);
  };
  for (int u = 0; u < n; u++) {
    if (inc[u].size() == 0) {
      dfs(u);
    }
  }
  
  // Try removing each vertex
  int result = 1000000007, target = 0;
  for (int removed = 0; removed < n; ++removed) {
    vector<int> dp(n);
    
    for (int i = 0; i < (int)topo.size(); i++) {
      const int u = topo[i];
      if (removed == u) {
        continue;
      }

      bool endpoint =
          adj[u].size() == 0 || (adj[u].size() == 1 && adj[u][0] == removed);

      if (endpoint) {
        dp[u] = 0;
      } else {
        for (int v : adj[u]) {
          if (v == removed) {
            continue;
          }
          int cand = dp[v] + 1;
          if (cand > dp[u]) {
            dp[u] = cand;
          }
        }
      }
    }
    
    int longest_path = *max_element(begin(dp), end(dp));
    if (longest_path < result) {
      result = longest_path;
      target = removed;
    }
  }
  
  cout << (target + 1) << " " << result << '\n';

  return 0;
}