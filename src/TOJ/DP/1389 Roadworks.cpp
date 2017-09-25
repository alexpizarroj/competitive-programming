#include <bits\stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
vector<vi> g;
int dp[100005][2]; // [u][0] = sum of [v][1] of sons, [u][1] opt at u
int couple[100005]; // in a best matching of the subtree rooted at u, couple[u] is the child we'll be paired with
vector<ii> ans;

void dfs(const int u, const int parent)
{
  // Solution excluding u from the matching ([u][0])
  dp[u][0] = dp[u][1] = 0;
  couple[u] = -1;
  for(int i = 0; i < (int)g[u].size(); i++)
  {
    const int v = g[u][i];
    if (v == parent)
      continue;
    dfs(v, u);
    dp[u][0] += dp[v][1];
  }
  // Best matching for subtree rooted at u ([u][1]);
  dp[u][1] = dp[u][0];
  for(int i = 0; i < (int)g[u].size(); i++)
  {
    const int v = g[u][i];
    if (v == parent)
      continue;
    int cand = 1 + dp[v][0] + (dp[u][0] - dp[v][1]);
    if (cand > dp[u][1])
    {
      couple[u] = v;
      dp[u][1] = cand;
    }
  }
}

void rec(const int u, const int parent)
{
  // Solutions of the children of couple[u]
  if (couple[u] != -1)
  {
    const int v = couple[u];
    ans.push_back(make_pair(min(u, v), max(u, v)));
    for(int i = 0; i < (int)g[v].size(); i++)
    {
      const int t = g[v][i];
      if (t == u)
        continue;
      rec(t, v);
    }
  }
  // Solution at these subtrees
  for(int i = 0; i < (int)g[u].size(); i++)
  {
    const int v = g[u][i];
    if (v == parent || v == couple[u])
      continue;
    rec(v, u);
  }
}

int main()
{
  // Fast IO
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n, m;
  while (cin >> n >> m)
  {
      vector<ii> edges(m);
      g.assign(n+1, vi());
      for(int i = 0; i < m; i++)
      {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        edges[i].first = a;
        edges[i].second = b;
      }
      dfs(1, -1);

      ans.clear();
      rec(1, -1);
      sort(begin(ans), end(ans));

      cout << dp[1][1] << '\n';
      for(int i = 0; i < m; i++)
      {
        ii x = edges[i];
        if (x.first > x.second)
          swap(x.first, x.second);
        if (binary_search(begin(ans), end(ans), x))
          cout << edges[i].first << " " << edges[i].second << '\n';  
      }
  }

  return 0;
}
