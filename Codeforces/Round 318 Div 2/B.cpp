#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using vi = vector<int>;
using ii = pair<int, int>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, m;
  while (cin >> n >> m) {
    vector<vi> adj(n);
    vector<vector<bool>> knows(n, vector<bool>(n, false));
    
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      a -= 1, b -= 1;
      adj[a].push_back(b);
      adj[b].push_back(a);
      knows[a][b] = knows[b][a] = true;
    }
    
    int ans = inf;
    for (int u = 0; u < n; ++u) for (int v : adj[u])
    {
      for (int s = 0; s < n; ++s) {
        if (s == u || s == v) {
          continue;
        }
        if (!knows[u][s] || !knows[v][s]) {
          continue;
        }
        int cand = (int)adj[u].size() - 2;
        cand += (int)adj[v].size() - 2;
        cand += (int)adj[s].size() - 2;
        ans = min(ans, cand);
      }
    }
    cout << (ans == inf ? -1 : ans) << '\n';
  }
  
  return 0;
}
