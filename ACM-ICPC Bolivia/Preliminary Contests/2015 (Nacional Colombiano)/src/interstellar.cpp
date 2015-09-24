// Solved by Alex Pizarro
#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using ii = pair<int, int>;

struct Edge {
  int next, mon, dur;
};
using Graph = vector<vector<Edge>>;

struct DEdge {  // Dijkstra's algorithm Edge
  int next, mon, dur, jmp;
};

bool operator<(const DEdge& lhs, const DEdge& rhs) {
  if (lhs.mon != rhs.mon) {
    return lhs.mon > rhs.mon;
  } else if (lhs.dur != rhs.dur) {
    return lhs.dur > rhs.dur;
  }
  return lhs.jmp > rhs.jmp;
}

vector<vector<DEdge>> dijkstra(const Graph& g, const int src) {
  const int n = g.size();
  const DEdge kUnreached = (DEdge){-1, inf, inf, inf};
  priority_queue<DEdge, vector<DEdge>> pq;
  vector<vector<DEdge>> best(n, vector<DEdge>(n, kUnreached));

  pq.push((DEdge){src, 0, 0, 0});
  best[0][src].mon = best[0][src].dur = best[0][src].jmp = 0;
  // cerr << "Solving for a graph with n=" << n << endl;

  while (!pq.empty()) {
    DEdge e1 = pq.top();
    pq.pop();

    if (e1 < best[e1.jmp][e1.next]) {
      continue;
    }
    // cerr << "Current iteration u=" << e1.next << ", jmp=" << e1.jmp << endl;

    if (e1.jmp == n - 1) {
      continue;
    }

    for (const Edge& e2 : g[e1.next]) {
      DEdge c = (DEdge){e2.next, e1.mon + e2.mon, e1.dur + e2.dur, e1.jmp + 1};
      if (best[c.jmp][e2.next] < c) {
        best[c.jmp][e2.next] = c;
        pq.push(c);
      }
    }
  }

  return best;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  bool first_case = true;
  int p, f, q;

  while (cin >> p >> f >> q) {
    if (!first_case) cout << ".\n";
    first_case = false;

    vector<string> planets(p);
    for (int i = 0; i < p; ++i) {
      cin >> planets[i];
    }
    sort(begin(planets), end(planets));

    auto get_planet_id = [&](const string& p) -> int {
      auto it = lower_bound(begin(planets), end(planets), p);
      return distance(begin(planets), it);
    };

    Graph g(p, vector<Edge>());
    for (int i = 0; i < f; ++i) {
      string pa, pb;
      int mon, dur;
      cin >> pa >> pb >> mon >> dur;

      int ida = get_planet_id(pa), idb = get_planet_id(pb);
      g[ida].push_back((Edge){idb, mon, dur});
    }

    string start_planet_str;
    cin >> start_planet_str;
    const int start_planet = get_planet_id(start_planet_str);

    if (q > 0) {
      auto results = dijkstra(g, start_planet);

      vector<vector<ii>> precalc(p, vector<ii>(p, ii(inf, inf)));
      for (int j = 0; j < p; j++) {
        precalc[0][j].first = results[0][j].mon;
        precalc[0][j].second = results[0][j].dur;
      }
      for (int i = 1; i < p; ++i) {
        for (int j = 0; j < p; ++j) {
          precalc[i][j].first = precalc[i - 1][j].first;
          precalc[i][j].second = precalc[i - 1][j].second;

          ii cand(results[i][j].mon, results[i][j].dur);
          if (cand < precalc[i][j]) {
            precalc[i][j] = cand;
          }
        }
      }

      for (int i = 0; i < q; ++i) {
        string pb;
        int max_jumps, idb;
        cin >> pb >> max_jumps;
        idb = get_planet_id(pb);
        max_jumps = min(max_jumps + 1, p - 1);

        int mon = precalc[max_jumps][idb].first;
        int dur = precalc[max_jumps][idb].second;

        if (mon == inf) {
          cout << "* *\n";
        } else {
          cout << mon << " " << dur << '\n';
        }
      }
    }
  }

  return 0;
}
