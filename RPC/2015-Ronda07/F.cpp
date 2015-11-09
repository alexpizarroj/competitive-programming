#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vector<string> grid;

char grid_at(ii p) {
  return grid[p.first][p.second];
}

int id_at(ii p) {
  return (p.first * 10) + p.second;
}

ii pair_from_id(int id) {
  return ii(id / 10, id % 10);
}

void setup_graph(vector<vii>& adj) {
  for (int i = 0; i < 10; ++i) for (int j = 0; j < 10; ++j) {
    for (int a = 0; a < 10; ++a) for (int b = 0; b < 10; ++b) {
      if (abs(i - a) != 2 || abs(j - b) != 2) {
        continue;
      }
      
      ii p1(i, j), p2(a, b);
      ii pmid((i + a) / 2, (j + b) / 2);
      if ((grid_at(p1) == 'W' || grid_at(p1) == '#')
          && (grid_at(p2) == 'W' || grid_at(p2) == '#')
          && grid_at(pmid) == 'B') {
        int u = id_at(p1), v = id_at(p2), w = id_at(pmid);
        adj[u].push_back(ii(w, v));
      }
    }
  }
}

int max_moves(int u, bitset<100> taken, const int src, const vector<vii>& adj) {
  int best = 0;
  
  for (int i = 0; i < (int)adj[u].size(); ++i) {
    int uvmid = adj[u][i].first, v = adj[u][i].second;
    
    if (taken.test(uvmid)) {
      continue;
    }
    
    char ch = grid_at(pair_from_id(v));
    if (ch == 'W' && v != src) {
      continue;
    }
    
    bitset<100> new_taken(taken);
    new_taken.set(uvmid);
    int cand = 1 + max_moves(v, new_taken, src, adj);
    
    best = max(best, cand);
  }
  
  return best;
}

void solve() {
  grid.resize(10);
  for (int i = 0; i < 10; ++i) {
    cin >> grid[i];
  }
  
  vector<vii> adj(100, vii());
  setup_graph(adj);
  
  int ans = 0;
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (grid[i][j] == 'W') {
        const int src = id_at(ii(i, j));
        int cand = max_moves(src, bitset<100>(), src, adj);
        ans = max(ans, cand);
      }
    }
  }
  
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int tc;
  cin >> tc;
  
  for (int i = 0; i < tc; ++i) {
    solve();
  }
  
  return 0;
}
