#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using vi = vector<int>;
using ii = pair<int, int>;

struct Edge {
  Edge(int a, int b) : next(a), weight(b) { }
  int next, weight;
  bool skip = false;
};

bool cmp_less(const Edge& e1, const Edge& e2) {
  return e1.weight < e2.weight;
}

bool cmp_greater(const Edge& e1, const Edge& e2) {
  return e1.weight > e2.weight;
}

bool operator<(const Edge& e1, const Edge& e2) {
  return cmp_greater(e1, e2);
}

vector<int> dijkstra(int src, const vector<vector<Edge>>& adj) {
  const int n = adj.size();
  vector<int> dist(n, inf);
  dist[src] = 0;
  
  priority_queue<Edge, vector<Edge>> pq;
  pq.push(Edge(src, 0));
  
  while (!pq.empty()) {
    const Edge e = pq.top();
    pq.pop();
    
    if (e.weight > dist[e.next]) {
      continue;
    }
    
    for (auto&& e2 : adj[e.next]) {
      int cand = dist[e.next] + e2.weight;
      if (cand < dist[e2.next]) {
        dist[e2.next] = cand;
        pq.push(Edge(e2.next, cand));
      }
    }
  }
  
  return dist;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, m, k;
  while (cin >> n >> m >> k) {
    vi path(k);
    for (int i = 0; i < k; ++i) {
      cin >> path[i];
      path[i] -= 1;
    }
    
    vector<vector<Edge>> adj(n, vector<Edge>());
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      a -= 1, b -= 1;
      adj[a].push_back(Edge(b, c));
      adj[b].push_back(Edge(a, c));
    }
    
    for (int i = 1; i < k; ++i) {
      int u = path[i - 1], v = path[i];
      sort(begin(adj[u]), end(adj[u]), cmp_less);
      
      for (int j = 0; j < (int)adj[u].size(); ++j) {
        if (adj[u][j].next == v) {
          adj[u][j].skip = true;
          break;
        }
      }
    }
    
    vi fsrc = dijkstra(0, adj), fdst = dijkstra(n - 1, adj);
    
    bool ok = false;
    for (int u = 0; !ok && u < n; ++u) {
      for (int i = 0; i < (int)adj[u].size(); ++i) {
        if (adj[u][i].skip) continue;
        int v = adj[u][i].next;
        int we = adj[u][i].weight;
        if (fsrc[u] + we + fdst[v] == fsrc[n - 1]) {
          //cerr << "Use edge " << (u + 1) << "->" << (v + 1) << endl;
          ok = true;
          break;
        }
      }
    }
    
    cout << (ok ? "yes" : "no") << endl;
  }
  
  return 0;
}
