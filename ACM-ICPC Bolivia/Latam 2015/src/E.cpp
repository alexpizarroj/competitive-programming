#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using vi = vector<int>;
using vii = vector<ii>;

vector<ii> explore(int u, vector<vi>& g, vi& visited, const vi& n_cost, const vi& m_cost) {
  ii res[2] = {ii(0, 0), ii(0, 0)};
  
  queue<int> q;
  q.push(u);
  visited[u] = 1;
  
  while (!q.empty()) {
    u = q.front();
    q.pop();
    
    if (u < (int)n_cost.size()) {
      res[0].first  += 1;
      res[0].second += n_cost[u];
    } else {
      res[1].first  += 1;
      res[1].second += m_cost[u - (int)n_cost.size()];
    }
    
    for (int v : g[u]) {
      if (visited[v] != 0) continue;
      q.push(v);
      visited[v] = 1;
    }
  }
  
  return vector<ii>({res[0], res[1]});
}

int ks_rec(int cur, int money, const int n, const vi& values, const vi& cost, vector<vi>& dp) {
  if (cur == n) return 0;
  int &ans = dp[cur][money];
  if (ans != -1) return ans;
  
  ans = ks_rec(cur + 1, money, n, values, cost, dp);
  if (cost[cur] <= money) {
    int cand = values[cur] + ks_rec(cur + 1, money - cost[cur], n, values, cost, dp);
    ans = max(ans, cand);
  }
  
  return ans;
}

int knapsack(const vi& values, const vi& cost, int budget) {
  const int n = values.size();
  
  vector<vi> dp(n, vi(budget + 1, -1));
  
  return ks_rec(0, budget, n, values, cost, dp);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, m, r, b;
  while (cin >> n >> m >> r >> b) {
    vi n_cost(n), m_cost(m);
    for (int i = 0; i < n; ++i) {
      cin >> n_cost[i];
    }
    for (int i = 0; i < m; ++i) {
      cin >> m_cost[i];
    }
    
    vector<vi> g(n + m, vi());
    for (int i = 0; i < r; ++i) {
      int x, y;
      cin >> x >> y;
      x -= 1, y -= 1;
      y += n;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    
    vi visited(n + m, 0);
    vi values[2], cost;
    
    for (int i = 0; i < n + m; ++i) {
      if (visited[i] != 0) continue;
      auto res = explore(i, g, visited, n_cost, m_cost);
      
      values[0].push_back(res[1].first - res[0].first);
      values[1].push_back(res[0].first - res[1].first);
      cost.push_back(res[0].second + res[1].second);
    }
    
    int res1 = n + knapsack(values[0], cost, b);
    int res2 = m + knapsack(values[1], cost, b);
    cout << res1 << " " << res2 << '\n';
  }
  
  return 0;
}
