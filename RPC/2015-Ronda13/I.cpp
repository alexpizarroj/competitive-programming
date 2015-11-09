#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using vi = vector<int>;
using ii = pair<int, int>;

ii get_farthest(int u, const vector<vi> &g, vi &dist) {
  int ans = u;

  queue<int> q;
  q.push(u);
  dist[u] = 0;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int v : g[cur]) {
      if (dist[v] != -1) continue;

      dist[v] = dist[cur] + 1;
      if (dist[ans] < dist[v]) {
        ans = v;
      }

      q.push(v);
    }
  }

  return make_pair(ans, dist[ans]);
}

int f(int n) { return (n + 1) / 2; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int C, L;
  while (cin >> C >> L) {
    vector<vi> g(C, vi());
    for (int i = 0; i < L; ++i) {
      int x, y;
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
    }

    vi v1(C, -1), v2(C, -1), ccd;

    for (int u = 0; u < C; ++u) {
      if (v1[u] != -1) continue;

      auto a = get_farthest(u, g, v1);
      auto b = get_farthest(a.first, g, v2);
      int diam = b.second;
      ccd.push_back(diam);
    }

    const int n = ccd.size();
    sort(begin(ccd), end(ccd));

    int result = inf;

    for (int p = 0; p < n; ++p) {
      int hub_cand = ccd.back();

      // with the longest
      if (n >= 2) {
        int q = (p == n - 1 ? n - 2 : n - 1);
        int cand = f(ccd[p]) + f(ccd[q]) + 1;
        hub_cand = max(hub_cand, cand);
      }

      // with the ones on the hub
      if (n >= 3) {
        // find the longest ones on the hub
        int q[2] = {n - 1, n - 2};
        for (int i = 0; i < 2; ++i) {
          if (q[i] == p) {
            q[i] = n - 3;
            break;
          }
        }
        // update da shit
        int cand = f(ccd[q[0]]) + f(ccd[q[1]]) + 2;
        hub_cand = max(hub_cand, cand);
      }

      result = min(result, hub_cand);
    }

    cout << result << endl;

    cerr << "size: " << ccd.size() << ", ccd:";
    for (int diam : ccd) cerr << " " << diam;
    cout << endl;
  }

  return 0;
}
