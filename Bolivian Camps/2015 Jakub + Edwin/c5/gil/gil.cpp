#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, m;
  cin >> n >> m;
  
  vector<vector<int>> adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x -= 1, y -= 1;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  
  bool ok = true;
  
  vector<int> dist(n, -1);
  for (int i = 0; ok && i < n; i++) {
    if (dist[i] == -1) {
      int cnt = 1;
      queue<int> q;
      
      q.push(i);
      dist[i] = 0;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
          if (dist[v] != -1) {
            continue;
          }
          
          cnt += 1;
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
      
      if (cnt == 1) {
        ok = false;
      }
    }
  }
  
  if (ok) {
    cout << "TAK\n";
    for (int i = 0; i < n; i++) {
      int m = dist[i] % 2;
      cout << (m == 0 ? 'K' : 'S') << '\n';
    }
    
  } else {
    cout << "NIE\n";
  }

  return 0;
}