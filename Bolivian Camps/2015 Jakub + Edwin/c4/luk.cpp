#include <bits/stdc++.h>
using namespace std;

bool works(const vector<vector<int>>& adj, int n_workers) {
  const int n = adj.size();
  vector<int> dp(n, 0);
  
  function<void(int, int)> dfs = [&](int u, int parent) {
    int ch = 0, sum = 0;
    for (int v : adj[u]) {
      if (v == parent) {
        continue;
      }
      dfs(v, u);
      
      ch += 1;
      sum += dp[v];
    }
    dp[u] = max(ch + sum - n_workers, 0);
  };
  dfs(0, -1);
  
  bool result = (dp[0] == 0);
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;
  
  vector<vector<int>> adj(n, vector<int>());
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a -= 1, b -= 1;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  int lo = 0, hi = n - 1;
  while (hi - lo > 1) {
    int mid = lo + (hi - lo) / 2;
    if (works(adj, mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  cout << hi << '\n';
  
  return 0;
}
