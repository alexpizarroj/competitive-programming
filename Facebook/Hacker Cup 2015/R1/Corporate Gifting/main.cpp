#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

struct ColoringData
{
  ColoringData() : cost1(-1), cost2(-1), color1(-1), color2(-1) { }
  long long cost1, cost2;
  int color1, color2;
};

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  int test_cases;
  cin >> test_cases;
  for(int tc = 1;  tc <= test_cases; tc++)
  {
    int n;
    cin >> n;

    vector<vi> G(n, vi());
    for(int i = 0; i < n; i++)
    {
      int parent;
      cin >> parent;
      if (parent == 0)
        continue;

      G[parent-1].push_back(i);
      G[i].push_back(parent-1);
    }

    vector<ColoringData> dp(n);
    vi parent(n, -1), visited(n, 0);
    stack<int> st;
    st.push(0);
    while (!st.empty())
    {
      const int u = st.top();

      if (visited[u] == 0)
      {
        visited[u] = 1;

        bool got_children = false;
        for(int i = 0; i < (int)G[u].size(); i++)
        {
          int v = G[u][i];
          if (v != parent[u])
          {
            parent[v] = u;
            st.push(v);
            got_children = true;
          }
        }

        if (got_children)
          continue;
        else
        {
          // This is a leaf 
          dp[u].cost1 = dp[u].color1 = 1;
          dp[u].cost2 = dp[u].color2 = 2;
        }
      }
      
      st.pop();
      if (dp[u].cost1 == -1)
      {
        // This is a not a leaf 
        // Go! Children data is already updated
        
        const int kDegree = (int)G[u].size() - (parent[u] == -1 ? 0 : 1);
        long long base_cost = 0;
        vector<long long> alt(kDegree + 2, 0);
        for(int i = 0; i < (int)G[u].size(); i++)
        {
          const int v = G[u][i];
          if (parent[v] == u)
          {
            base_cost += dp[v].cost1;
            if (dp[v].color1 <= kDegree + 1)
              alt[dp[v].color1] += dp[v].cost2 - dp[v].cost1;
          }
        }

        ColoringData &cd = dp[u];
        for(int i = 1; i <= kDegree + 1; i++)
        {
          const long long cand = alt[i] + base_cost + i;
          if (cd.cost1 == -1 || cd.cost1 > cand)
          {
            cd.cost2 = cd.cost1;
            cd.color2 = cd.color1;
            cd.cost1 = cand;
            cd.color1 = i;
          }
          else if (cd.cost2 == -1 || cd.cost2 > cand)
          {
            cd.cost2 = cand;
            cd.color2 = i;
          }
        }
      }
    }
    
    long long ans = dp[0].cost1;
    cout << "Case #" << tc << ": " << ans << "\n";

    /*
    int mx = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
      const int u = q.front();
      q.pop();

      if (parent[u] != -1 && dp[parent[u]].color1 == dp[u].color1)
        mx = max(mx, dp[u].color2);
      else
        mx = max(mx, dp[u].color1);

      for(int i = 0; i < (int)G[u].size(); i++)
      {
        const int v = G[u][i];
        if (parent[u] == v)
          continue;
        q.push(v);
      }
    }
    cout << "\tAmount of Different Colors is " << mx << endl;
    */
  }
  
  return 0;
}