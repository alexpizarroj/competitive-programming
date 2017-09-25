#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using vi = vector<int>;
using ii = pair<int, int>;

vector<vi> g;
vector<bool> go, stgo;
vector<int> dprs, dprc;
int ans_v, ans_t;

void dfs(const int u, const int parent) {
  stgo[u] = stgo[u] || go[u];

  int n_children_stgo = 0;
  for (int v : g[u]) {
    if (v == parent) continue;
    dfs(v, u);

    if (stgo[v]) {
      dprc[u] += dprc[v] + 2;
      stgo[u] = true;
      n_children_stgo += 1;
    }
  }

  if (n_children_stgo > 0) {
    dprs[u] = inf;
    for (int v : g[u]) {
      if (v == parent || !stgo[v]) continue;
      int cand = dprc[u] - (dprc[v] + 2) + (dprs[v] + 1);
      dprs[u] = min(dprs[u], cand);
    }
  }
}

void dfs2(const int u, const int parent) {
  cerr << u << ", parent=" << parent << endl;
  cerr << "\tdprs=" << dprs[u] << ", dprc=" << dprc[u] << ", stgo=" << stgo[u]
       << endl;

  for (int v : g[u]) {
    if (v == parent) continue;
    dfs2(v, u);
  }
}

void dfs3(const int u, const int parent) {
  for (int v : g[u]) {
    if (v == parent) continue;

    // Save the values before changing them
    int o_dprs_u, o_dprc_u;
    int o_dprs_v, o_dprc_v;
    bool o_stgo_u, o_stgo_v;
    o_dprs_u = dprs[u], o_dprc_u = dprc[u];
    o_dprs_v = dprs[v], o_dprc_v = dprc[v];
    o_stgo_u = stgo[u], o_stgo_v = stgo[v];

    // Update the values of U
    dprs[u] = 0;
    dprc[u] = 0;
    stgo[u] = go[u];
    int n_children_stgo = 0;
    for (int k : g[u]) {
      if (k == v) continue;
      if (stgo[k]) {
        dprc[u] += dprc[k] + 2;
        stgo[u] = true;
        n_children_stgo += 1;
      }
    }
    if (n_children_stgo > 0) {
      dprs[u] = inf;
      for (int k : g[u]) {
        if (k == v || !stgo[k]) continue;
        int cand = dprc[u] - (dprc[k] + 2) + (dprs[k] + 1);
        dprs[u] = min(dprs[u], cand);
      }
    }

    // Update the values of V
    dprs[v] = 0;
    dprc[v] = 0;
    stgo[v] = go[v];
    n_children_stgo = 0;
    for (int k : g[v]) {
      if (stgo[k]) {
        dprc[v] += dprc[k] + 2;
        stgo[v] = true;
        n_children_stgo += 1;
      }
    }
    if (n_children_stgo > 0) {
      dprs[v] = inf;
      for (int k : g[v]) {
        if (!stgo[k]) continue;
        int cand = dprc[v] - (dprc[k] + 2) + (dprs[k] + 1);
        dprs[v] = min(dprs[v], cand);
      }
    }

    // cerr << "Switch (" << u << " -> " << v << ")" << endl;
    // cerr << "\tU: dprc=" << dprc[u] << ", dprs=" << dprs[u] << ", stgo=" <<
    // stgo[u] << endl;
    // cerr << "\tV: dprc=" << dprc[v] << ", dprs=" << dprs[v] << ", stgo=" <<
    // stgo[v] << endl;

    // Update the answer so far
    if (dprs[v] < ans_t || (dprs[v] == ans_t && v < ans_v)) {
      ans_v = v, ans_t = dprs[v];
    }

    // Try vertices of this subtree
    dfs3(v, u);

    // Restore original values
    dprs[u] = o_dprs_u, dprc[u] = o_dprc_u;
    dprs[v] = o_dprs_v, dprc[v] = o_dprc_v;
    stgo[u] = o_stgo_u, stgo[v] = o_stgo_v;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  while (cin >> n >> m) {
    g.assign(n, vi());
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      a -= 1, b -= 1;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    go.assign(n, false);
    for (int i = 0; i < m; ++i) {
      int x;
      cin >> x;
      x -= 1;
      go[x] = true;
    }

    stgo.assign(n, false);
    dprc.assign(n, 0);
    dprs.assign(n, 0);
    dfs(0, -1);

    // dfs2(0, -1);

    ans_v = 0, ans_t = dprs[0];
    dfs3(0, -1);

    cout << (ans_v + 1) << endl
         << ans_t << endl;
  }

  return 0;
}
