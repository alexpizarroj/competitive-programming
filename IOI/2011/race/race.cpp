// C includes
#include <cstdio>
#include <cstring>
#include <cassert>
// C++ includes
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> Graph;
const int inf = int(1e9) + 7;

struct DirEntry {
  int iterVersion, hops;
};
DirEntry A[1000005];       // Directory
vi dfs_desc, dfs_parent;   // Root information
vi dfs_aux, dfs_aux_hops;  // Auxiliary vectors
int currentIter;           // Current iteration

// Roots the Tree g at vertex u.
// Fills dfs_desc and dfs_parent with necessary data.
void rootTree(const Graph &g, int u) {
  stack<int> st;
  vi dfs_visited(g.size(), 0);

  dfs_desc.assign(g.size(), 0);
  dfs_parent.assign(g.size(), -1);
  st.push(u);
  // printf("\tFilling descendants tables\n");
  while (!st.empty()) {
    u = st.top();
    // BEFORE CHILDREN: Descendants stacking
    // printf("\t\tProcessing children of %d\n", u);
    if (dfs_visited[u] == 0) {
      bool gotChildren = false;
      for (int i = 0; i < (int)g[u].size(); i++) {
        int v = g[u][i].first;
        if (v != dfs_parent[u]) {
          dfs_parent[v] = u;
          st.push(v);
          gotChildren = true;
          // printf("\t\tStacking node %d (parent %d)\n", v, u);
        }
      }
      // If we stacked children, we should wait the processing
      if (gotChildren) {
        dfs_visited[u] = 1;
        // printf("\t\tChildren found. Skipping de-stacking.\n");
        continue;
      }
    }
    // AFTER CHILDREN: Descendants summation
    // if ( dfs_visited[u] == 0 ) printf("\t\tNo children found.\n");
    // printf("\t\tEnding node %d\n", u);
    dfs_visited[u] = 1;
    dfs_desc[u] = 0;
    st.pop();
    for (int i = 0; i < (int)g[u].size(); i++) {
      int v = g[u][i].first;
      if (dfs_parent[v] == u) {
        assert(dfs_visited[v] == 1);
        dfs_desc[u] += dfs_desc[v] + 1;
      }
    }
  }
  // printf("\tDescendants got filled correctly.\n");
}

// Returns the Central Node of the (Sub)tree rooted at u.
int getCentralNode(const Graph &g, int u) {
  queue<int> q;
  int central = -1;
  const int n = dfs_desc[u] + 1, half_n = n / 2;

  q.push(u);
  while (!q.empty()) {
    u = q.front();
    q.pop();
    bool isCentral = true;
    // printf("\tChecking if node %d is central.\n", u);
    for (int i = 0; i < (int)g[u].size(); i++) {
      int v = g[u][i].first;
      if (v != dfs_parent[u]) {
        int nd = dfs_desc[v] + 1;
        if (nd > half_n) isCentral = false;
        q.push(v);
      }
    }
    if (isCentral && dfs_parent[u] != -1) {
      int nd = (n - 1 - dfs_desc[u]);
      if (nd > half_n) isCentral = false;
    }
    if (isCentral) {
      central = u;
      // printf("\tCentral node found: %d\n", central);
      break;
    }
  }
  assert(central != -1);
  return central;
}

int bestPathPassingNode(const Graph &g, const int u, const int K) {
  int ans = inf;
  queue<ii> q;
  vii roadsFound;

  dfs_aux[u] = -1;
  A[0].iterVersion = currentIter, A[0].hops = 0;
  for (int i = 0; i < (int)g[u].size(); i++) {
    int v = g[u][i].first, dist = g[u][i].second;
    if (dist <= K) {
      q.push(ii(v, dist));
      dfs_aux[v] = u;
      dfs_aux_hops[v] = 1;
    }
    // Sub-tree traversal
    while (!q.empty()) {
      v = q.front().first, dist = q.front().second;
      q.pop();
      assert(dist <= K);
      // Save road for directory update
      roadsFound.push_back(ii(dist, dfs_aux_hops[v]));
      // Process neighbours
      for (int j = 0; j < (int)g[v].size(); j++) {
        const int w = g[v][j].first;
        if (w != dfs_aux[v]) {
          int newdist = dist + g[v][j].second;
          dfs_aux[w] = v;
          dfs_aux_hops[w] = dfs_aux_hops[v] + 1;
          if (newdist <= K) q.push(ii(w, newdist));
        }
      }
      // Check for a valid path using v
      if (K >= dist && A[K - dist].iterVersion == currentIter) {
        int cand = A[K - dist].hops + dfs_aux_hops[v];
        if (cand < ans) ans = cand;
      }
    }
    // Directory update
    for (int k = 0; k < (int)roadsFound.size(); k++) {
      int d = roadsFound[k].first, hops = roadsFound[k].second;
      if (A[d].iterVersion != currentIter || A[d].hops > hops) {
        A[d].iterVersion = currentIter;
        A[d].hops = hops;
      }
    }
    roadsFound.clear();
  }
  return ans;
}

int best_path_imp(Graph &g, const int K) {
  // Root the graph
  rootTree(g, 0);
  dfs_aux.resize(g.size());
  dfs_aux_hops.resize(g.size());
  memset(A, 0, sizeof A);
  // While there are (sub)trees to check, let's rock!
  int ans = inf;
  queue<int> Q;
  Q.push(0);
  for (currentIter = 1; !Q.empty(); currentIter++) {
    const int root = Q.front();
    Q.pop();
    if (dfs_desc[root] == 0) continue;
    // printf("Processing sub-tree of size %d, root=%d\n", dfs_desc[root]+1,
    // root);
    int u = getCentralNode(g, root);
    // printf("Trying central node %d\n", u);
    ans = min(ans, bestPathPassingNode(g, u, K));
    // printf("Done processing. Now I'll split the tree.\n");
    // Remaining trees queueing
    for (int i = 0; i < (int)g[u].size(); i++) {
      int v = g[u][i].first;
      if (v != dfs_parent[u]) {
        Q.push(v);
        // Remove u as parent of his children
        dfs_parent[v] = -1;
      } else {
        Q.push(root);
        // Remove u as child of his parent
        int nd = dfs_desc[u] + 1, cur = v;
        while (cur != -1) {
          dfs_desc[cur] -= nd;
          cur = dfs_parent[cur];
        }
      }
      // Remove the edge (v -> u)
      int nc = (int)g[v].size();
      for (int pos = 0; pos < nc; pos++)
        if (g[v][pos].first == u) {
          swap(g[v][pos], g[v][nc - 1]);
          g[v].pop_back();
          break;
        }
    }
  }
  return ans;
}

int best_path(int N, int K, int H[][2], int L[]) {
  Graph g(N, vii());
  for (int i = 0; i < N - 1; i++) {
    int u = H[i][0], v = H[i][1], cost = L[i];
    g[u].push_back(ii(v, cost));
    g[v].push_back(ii(u, cost));
  }
  int ret = best_path_imp(g, K);
  return (ret == inf ? -1 : ret);
}
