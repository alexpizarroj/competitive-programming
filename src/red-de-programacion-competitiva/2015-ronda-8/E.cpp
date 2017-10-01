#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using vi = vector<int>;
using ii = pair<int, int>;

struct Edge {
  Edge(int a, int b) : next(a), weight(b) { }
  int next, weight;
};

bool operator<(const Edge& e1, const Edge& e2) {
  return e1.weight > e2.weight;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, m, k;
  while (cin >> n >> m >> k) {
    for (int i = 0; i < k; ++i) {
      int x;
      cin >> x;
    }
    
    vector<vector<Edge>> adj(n, vector<Edge>());
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      a -= 1, b -= 1;
      adj[a].push_back(Edge(b, c));
      adj[b].push_back(Edge(a, c));
    }
    
    vector<bool> mult(n, false);
    vector<int> dist(n, inf);
    dist[0] = 0;
    
    priority_queue<Edge, vector<Edge>> pq;
    pq.push(Edge(0, 0));
    
    while (!pq.empty()) {
      const Edge e = pq.top();
      pq.pop();
      
      if (e.weight > dist[e.next]) {
        continue;
      }
      
      //cerr << "Current vertex is " << e.next << endl;
      for (auto&& e2 : adj[e.next]) {
        int cand = dist[e.next] + e2.weight;
        //cerr << "\tcand is " << cand << " against " << dist[e2.next] << endl;
        if (cand < dist[e2.next]) {
          //cerr << "\tupdate from " << e.next << " to " << e2.next << endl;
          dist[e2.next] = cand;
          mult[e2.next] = mult[e.next];
          pq.push(Edge(e2.next, cand));
        } else if (cand == dist[e2.next]) {
          //cerr << "\tnew duplicate from " << e.next << " to " << e2.next << endl;
          mult[e2.next] = true;
        }
      }
    }
    
    //for (int i = 0; i < n; ++i) cerr << mult[i] << " " ; cerr << '\n';
    cout << (mult[n - 1] ? "yes" : "no") << endl;
  }
  
  return 0;
}
