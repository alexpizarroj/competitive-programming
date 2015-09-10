#include <bits/stdc++.h>
using namespace std;

struct MfEdge {
  int v, cap;
  int backid; // id to the back edge
};

struct MaxFlow {
  vector<vector<int>> g;  // integers represent edges' ids
  vector<MfEdge> edges;   // edges.size() should always be even
  int n, s, t;            // n = # vertices, s = src vertex, t = sink vertex

  int find_path() {
    const int inf = int(1e9 + 7);
    vector<int> visited(n, 0), from(n, -1), used_edge(n, -1);
    queue<int> q;
    int u, v, f;

    q.push(s);
    visited[s] = true;
    while (!visited[t] && !q.empty()) {
      u = q.front();
      q.pop();
      for (int eid : g[u]) {
        int v = edges[eid].v;
        if (edges[eid].cap > 0 && !visited[v]) {
          from[v] = u, used_edge[v] = eid;
          q.push(v);
          visited[v] = true;
          if (v == t) {
            break;
          }
        }
      }
    }

    f = inf;
    if (visited[t]) {
      for (v = t; from[v] > -1; v = from[v]) {
        f = min(edges[used_edge[v]].cap, f);
      }
      for (v = t; from[v] > -1; v = from[v]) {
        int backid = edges[used_edge[v]].backid;
        edges[used_edge[v]].cap -= f;
        edges[backid].cap += f;
      }
    }

    return (f == inf ? 0 : f);
  }

  int get() {
    int mf = 0, d;
    while ((d = find_path())) mf += d;
    return mf;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, cas = 1;
  while (cin >> n, n > 0) {
    MaxFlow mf;
    cin >> mf.s >> mf.t;
    mf.s -= 1, mf.t -= 1;
    
    mf.n = n;
    mf.g.assign(n, vector<int>());
    
    int m;
    cin >> m;
    for (int i = 0, eid = 0; i < m; i += 1, eid += 2) {
      int a, b, cap;
      cin >> a >> b >> cap;
      a -= 1, b -= 1;
      
      mf.edges.push_back((MfEdge){b, cap, eid + 1});
      mf.edges.push_back((MfEdge){a, cap, eid});
      mf.g[a].push_back(eid);
      mf.g[b].push_back(eid + 1);
    }
    
    int result = mf.get();
    cout << "Network " << cas << "\nThe bandwidth is " << result << ".\n\n";
    cas += 1;
  }
  
  return 0;
}
