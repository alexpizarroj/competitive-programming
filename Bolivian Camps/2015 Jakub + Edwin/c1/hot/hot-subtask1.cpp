#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  // Skip subtask 2
  if (n > 500) {
    return 0;
  }
  
  vector<vector<int>> adj(n, vector<int>());
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u -= 1, v -= 1;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  vector<vector<int>> dst(n, vector<int>(n, -1));
  
  for (int u = 0; u < n; u++) {
    vector<int>& cost = dst[u];
    
    queue<int> q;
    q.push(u);
    cost[u] = 0;
    
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for(int t : adj[v]) {
        if (cost[t] != -1) {
          continue;
        }
        cost[t] = cost[v] + 1;
        q.push(t);
      }
    }
  }
  
  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      for(int k = j + 1; k < n; k++) {
        if (dst[i][j] == dst[i][k] && dst[i][j] == dst[j][k]) {
          ans += 1;
        }
      }
    }
  }
  cout << ans << '\n';
  
  return 0;
}