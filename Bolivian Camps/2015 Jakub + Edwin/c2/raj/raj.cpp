#include <bits/stdc++.h>
using namespace std;

struct Node {
  int s, e;       // Interval covered by this node
  int son[2];     // Children of this node
  int val, lazy;  // Node info + Data to propagate
};

struct SegmentTree {
  vector<Node> T;

  SegmentTree(const vector<int>& vec) {
    const int N = vec.size();
    
    Node n;
    n.s = 0, n.e = N;
    n.son[0] = n.son[1] = -1;
    n.val = n.lazy = 0;

    T.reserve(4 * N);
    T.push_back(n);
    init(0, vec);
  }
  
  explicit SegmentTree(int N, int val) : SegmentTree(vector<int>(N, val)) {}
  
  explicit SegmentTree(int N) : SegmentTree(N, 0) {}

  void init(int u, const vector<int>& vec) {
    Node &n = T[u];
    if (n.e - n.s == 1)
    {
      n.val = vec[n.s];
      return;
    }
    
    int mid = (n.s + n.e) / 2;
    for (int i = 0; i < 2; i++) {
      Node c(n);
      if (i == 0)
        c.e = mid;
      else {
        c.son[0] = -1;
        c.s = mid;
      }
      n.son[i] = T.size();
      T.push_back(c);
      init(n.son[i], vec);
    }
    
    n.val = max(T[n.son[0]].val, T[n.son[1]].val);
  }

  void update(int u, int le, int ri, int val) {
    Node &n = T[u];
    if (n.e <= le || n.s >= ri) return;

    if (n.s == le && n.e == ri) {
      n.lazy = max(n.lazy, val);
      return;
    }

    if (le < T[n.son[0]].e) {
      update(n.son[0], le, min(T[n.son[0]].e, ri), val);
      update(n.son[1], max(T[n.son[1]].s, le), ri, val);
    } else {
      update(n.son[1], max(T[n.son[1]].s, le), ri, val);
    }
    n.val = max(n.val, val);
  }

  void push_lazy(int u) {
    Node &n = T[u];
    if (n.lazy == 0) return;

    n.val = max(n.val, n.lazy);
    for (int i = 0; i < 2; i++) {
      if (n.son[i] != -1) {
        T[n.son[i]].lazy = max(T[n.son[i]].lazy, n.lazy);
      }
    }
    n.lazy = 0;
  }

  int query(int u, int le, int ri) {
    Node &n = T[u];
    if (n.e <= le || n.s >= ri) return 0;

    push_lazy(u);
    if (n.s == le && n.e == ri) return n.val;

    int res = query(n.son[0], le, min(T[n.son[0]].e, ri));
    res = max(res, query(n.son[1], max(T[n.son[1]].s, le), ri));
    return res;
  }
};

vector<int> get_topo_sort(const vector<vector<int>>& adj,
                          const vector<vector<int>>& inc) {
  const int n = adj.size(), seen_never = 0, seen_before = 1;
  vector<int> topo, seen(n, seen_never);
  topo.reserve(n);

  auto dfs = [&](int u) -> void {
    if (seen[u] != seen_never) {
      return;
    }

    stack<pair<int, int>> st;
    seen[u] = seen_before;
    st.push(make_pair(u, 0));

    while (!st.empty()) {
      auto p = st.top();
      st.pop();

      u = p.first;

      bool wait_for_children = false;
      for (int i = p.second; i < (int)adj[u].size(); ++i) {
        const int v = adj[u][i];
        if (seen[v] == seen_before) {
          continue;
        }

        st.push(make_pair(u, i + 1));

        seen[v] = seen_before;
        st.push(make_pair(v, 0));

        wait_for_children = true;
        break;
      }

      if (!wait_for_children) {
        topo.push_back(u);
      }
    }
  };

  for (int u = 0; u < n; u++) {
    if (inc[u].size() == 0) {
      dfs(u);
    }
  }

  assert((int)topo.size() == n);
  return topo;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n, vector<int>()), inc(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a -= 1, b -= 1;
    adj[a].push_back(b);
    inc[b].push_back(a);
  }
  
  vector<int> topo = get_topo_sort(adj, inc);
  vector<int> topo_id(n);
  for (int i = 0; i < n; i++) {
    topo_id[topo[i]] = i;
  }
  
  // max_left[u] = longest length a path starting from u can have
  vector<int> max_left(n); 
  for (int i = 0; i < n; ++i) {
    const int u = topo[i];
    if (adj[u].size() == 0) {
      max_left[i] = 0;
    } else {
      for (int v : adj[u]) {
        int cand = max_left[topo_id[v]] + 1;
        if (cand > max_left[i]) {
          max_left[i] = cand;
        }
      }
    }
  }
  
  // max_right[u] = longest length a path ending at u can have
  vector<int> max_right(n);
  for (int i = n - 1; i >= 0; --i) {
    const int u = topo[i];
    if (inc[u].size() == 0) {
      max_right[i] = 0;
    } else {
      for(int v : inc[u]) {
        int cand = max_right[topo_id[v]] + 1;
        if (cand > max_right[i]) {
          max_right[i] = cand;
        }
      }
    }
  }
  
  vector<int> len1(n);
  {
    SegmentTree st_max_right(max_right);
    for (int u = 0; u < n; u++) {
      const int idx = topo_id[u];
      len1[idx] = st_max_right.query(0, idx + 1, n);
    }
  }
  
  vector<int> len2(n);
  {
    SegmentTree st_max_left(max_left);
    for (int u = 0; u < n; u++) {
      const int idx = topo_id[u];
      len2[idx] = st_max_left.query(0, 0, idx);
    }
  }
  
  SegmentTree st_info(n, -1000000007);
  for (int u = 0; u < n; u++) {
    const int idx_u = topo_id[u];
    for (int v : adj[u]) {
      const int idx_v = topo_id[v];
      assert(idx_v < idx_u); // Right here, idx_v < idx_u should hold
      
      int path_len = max_left[idx_v] + 1 + max_right[idx_u];
      st_info.update(0, idx_v + 1, idx_u, path_len);
    }
  }

  int ans_vertex = -1, ans_path_len = 1000000007;
  for (int u = 0; u < n; u++) {
    const int idx = topo_id[u];
    int len3 = st_info.query(0, idx, idx + 1);
    int cand = max(max(len1[idx], len2[idx]), len3);
    if (cand < ans_path_len) {
      ans_path_len = cand;
      ans_vertex = u + 1;
    }
  }
  
  cout << ans_vertex << " " << ans_path_len << '\n';
  
  return 0;
}

