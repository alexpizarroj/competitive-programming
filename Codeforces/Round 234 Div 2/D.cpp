#include <bits\stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  const int inf = 1000000007;
  int n, m, k;
  while (cin >> n >> m >> k)
  {
    int next = 0;
    vector<int> group(n);
    for(int j = 0; j < k; j++)
    {
      int c;
      cin >> c;
      for(int i = 0; i < c; i++)
        group[next+i] = j;
      next += c;
    }

    vector< vector<int> > g(n, vector<int>());
    vector< vector<int> > dist(k, vector<int>(k, inf));
    for(int i = 0; i < m; i++)
    {
      int u, v, x;
      cin >> u >> v >> x;
      u -= 1, v -= 1;

      if (x == 0)
      {
        g[u].push_back(v);
        g[v].push_back(u);
      }

      u = group[u];
      v = group[v];
      if (u != v)
      {
        dist[u][v] = dist[v][u] = min(dist[u][v], x);
      }
    }

    vector<int> cc(n, -1);
    next = 0;
    for(int start = 0; start < n; start++)
    {
      if (cc[start] != -1)
        continue;

      queue<int> q;
      cc[start] = next;
      q.push(start);
      while (!q.empty())
      {
        const int u = q.front();
        q.pop();
        for(int i = 0; i < (int)g[u].size(); i++)
        {
          const int v = g[u][i];
          if (cc[v] != -1)
            continue;
          cc[v] = next;
          q.push(v);
        }
      }

      next += 1;
    }

    bool types_are_valid = true;
    for(int i = 0; i < n-1; i++)
      if (group[i] == group[i+1] && cc[i] != cc[i+1])
      {
        types_are_valid = false;
        break;
      }

    if (types_are_valid)
    {
      cout << "Yes" << endl;

      for(int i = 0; i < k; i++)
        dist[i][i] = 0;
      for(int t = 0; t < k; t++)
        for(int u = 0; u < k; u++)
          for(int v = 0; v < k; v++)
            dist[u][v] = min(dist[u][v], dist[u][t] + dist[t][v]);
      for(int i = 0; i < k; i++)
      {
        for(int j = 0; j < k; j++)
          cout << (dist[i][j] == inf ? -1 : dist[i][j]) << " ";
        cout << endl;
      }
    }
    else
    {
      cout << "No" << endl;
    }
  }
  
  return 0;
}
