#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  using ii = pair<int, int>;
  const int inf = 1000000007;
  const map<char, char> kOpposite =
    {{'<', '>'}, {'>', '<'}, {'^', 'v'}, {'v', '^'}};
  const map<char, ii> kMove = 
    {{'<', {0, -1}}, {'>', {0, 1}}, {'^', {-1, 0}}, {'v', {1, 0}}};
  
  int n, m, max_cost;
  while (cin >> n >> m >> max_cost) {
    cin.ignore(1);
    if (n == 0) {
      break;
    }
    
    const int midx = n / 2, midy = m / 2;
    auto inside = [&](int x, int y) -> bool {
      return (0 <= x && x < n && 0 <= y && y < m);
    };
    auto get_id = [&](int x, int y) -> int {
      return (x * m) + y;
    };
    
    // DS for Dijkstra
    vector<int> dist(n * m, inf);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    
    vector<vector<ii>> adj(n * m, vector<ii>());
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        char ch;
        cin >> ch;
        
        if (i == midx && j == midy) {
          continue;
        }
        
        const int u = get_id(i, j);
        
        if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
          pq.push(make_pair(0, u));
        }
        
        vector<ii> neighbors = {kMove.at(ch), kMove.at(kOpposite.at(ch))};
        for (int k = 0; k < 2; ++k) {
          int x = i + neighbors[k].first, y = j + neighbors[k].second;
          if (!inside(x, y)) {
            continue;
          }
          
          const int v = get_id(x, y);
          adj[u].push_back(make_pair(v, k));
        }
      }
      cin.ignore(1);
    }
    
    while (!pq.empty()) {
      auto next = pq.top();
      pq.pop();
      
      const int u = next.second, cost = next.first;
      if (cost > dist[u]) {
        continue;
      }
      
      for (auto&& p : adj[u]) {
        const int v = p.first, u_v_cost = p.second;
        if (cost + u_v_cost < dist[v]) {
          dist[v] = cost + u_v_cost;
          pq.push(make_pair(dist[v], v));
        }
      }
    }
    
    cout << (dist[get_id(midx, midy)] <= max_cost ? "Sim\n" : "Nao\n");
  }
  
  return 0;
}