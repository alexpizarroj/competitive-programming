#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

void solve() {
  vector<string> grid(10);
  for (int i = 0; i < 10; i++) {
    cin >> grid[i];
  }
  
  vector<pair<ii, ii>> couples;
  
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        for (int m = 0; m < 10; m++) {
          if (abs(i - k) != 2 || abs(j - m) != 2) {
            continue;
          }

          ii a(i, j), b(k, m);
          if (a == b || a > b) {
            continue;
          }

          couples.emplace_back(a, b);
        }
      }
    }
  }

  int m = 0;
  vector<vector<int>> id(10, vector<int>(10, -1));
  vector<bool> is_light(100, false);
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (grid[i][j] == '#' || grid[i][j] == 'W') {
        id[i][j] = m;
        m += 1;
      }
      
      if (grid[i][j] == 'W') {
        is_light[id[i][j]] = true;
      }
    }
  }

  int n = 0;
  vector<vector<ii>> adj(m, vector<ii>());

  for (const auto& p : couples) {
    char ca = grid[p.first.first][p.first.second];
    char cb = grid[p.second.first][p.second.second];
    
    if (ca == 'B' || ca == '.' || cb == 'B' || cb == '.') {
      continue;
    }
    
    if (ca == 'W' && cb == 'W') {
      continue;
    }

    int x = (p.first.first + p.second.first) / 2;
    int y = (p.first.second + p.second.second) / 2;
    if (grid[x][y] != 'B') {
      continue;
    }
    
    int id1 = id[p.first.first][p.first.second];
    int id2 = id[p.second.first][p.second.second];
    adj[id1].emplace_back(n, id2);
    adj[id2].emplace_back(n, id1);
    n += 1;
  }
  
  int ans = 0, cur_light;

  function<void(int, long long, int)> rec =
      [&](int u, long long visited, int cnt) -> void {
        ans = max(ans, cnt);
        //cout << u << " " << visited << " " << cnt << endl;
        
        for (ii p : adj[u]) {
          int edge_id = p.first;
          bool used_edge = ((visited >> edge_id) & 1);
          if (used_edge) {
            continue;
          }
          
          const int v = p.second;
          if (cur_light != v && is_light[v] ) {
            continue;
          }

          long long new_visited = visited | (1LL << edge_id);
          rec(p.second, new_visited, cnt + 1);
        }
      };

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (grid[i][j] == 'W') {
        //cout << "TESTING LIGHT " << i << ", " << j << endl;
        cur_light = id[i][j];
        rec(cur_light, 0, 0);
      }
    }
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  for (int i = 0; i < tc; ++i) {
    solve();
  }

  return 0;
}

/*
2×3×5×7×11 × 13×17×19×23×29 × 31
every prime divisor with power 1 -> # different divisors = 11 -> 2^11
every prime divisor with power 2 -> # different divisors = 7  -> 3^7
every prime divisor with power 3 -> # different divisors = 5  -> 4^5
mayor cantidad de divisores es aprox 2.2k para numeros x <= 10^12

cardinalidad de la interseccion de los set de divisores <= 10^4
*/
