#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using vi = vector<int>;
using ii = pair<int, int>;

struct StNodeStairRi {
  using NodeType = StNodeStairRi;
  int val;  // Min of the interval
  int lazy; // Stair start pending to sum
  
  void set(const NodeType& from) {
    val = from.val;
    lazy = identity().lazy;
  }
  
  void merge(const NodeType& le, const NodeType& ri) {
    val = min(le.val, ri.val);
    lazy = identity().lazy;
  }
  
  void update(const NodeType& from) {
    int a = from.val + (s - from.s);
    if (lazy == identity().lazy || a < lazy) {
      val = a;
      lazy = a;
    }
  }
  
  void push_lazy(NodeType& le, NodeType &ri) {
    if (lazy == identity().lazy) {
      return;
    }
    
    const int le_a = lazy;
    const int le_b = le_a + (le.e - le.s) - 1;
    if (le.lazy == identity().lazy || le_a < le.lazy) {
      le.val = le_a;
      le.lazy = le_a;
    }
    
    const int ri_a = le_b + 1;
    if (ri.lazy == identity().lazy || ri_a < ri.lazy) {
      ri.val = ri_a;
      ri.lazy = ri_a;
    }
    
    lazy = identity().lazy;
  }
  
  static NodeType identity() {
    static auto tmp = (NodeType){inf, inf};
    return tmp;
  }
  
  // Internal tree data
  int son[2]; // Children of this node
  int s, e;   // Interval [s, e), covered by this node
};

template<class Node>
struct SegmentTree {
  using ValueProvider = function<Node(int)>;
  vector<Node> T;

  SegmentTree(int n, const ValueProvider& vp = [](int pos) {
    return Node::identity();
  }) {
    Node nd;
    nd.son[0] = nd.son[1] = -1;
    nd.s = 0, nd.e = n;

    T.reserve(4 * n);
    T.emplace_back(std::move(nd));
    
    init(vp, 0);
  }
  
  void init(const ValueProvider& vp, int u) {
    Node &n = T[u];
    
    if (n.e - n.s == 1)
    {
      n.set(vp(n.s));
      return;
    }
    
    Node le(n), ri(n);
    
    le.e = (n.s + n.e) / 2;
    n.son[0] = T.size();
    T.emplace_back(std::move(le));
    init(vp, n.son[0]);
    
    ri.s = le.e;
    n.son[1] = T.size();
    T.emplace_back(std::move(ri));
    init(vp, n.son[1]);
    
    n.merge(T[n.son[0]], T[n.son[1]]);
  }

  void update(int le, int ri, const Node& val, int u = 0) {
    Node &n = T[u];
    if (le >= n.e || n.s >= ri) return;

    if (n.s == le && n.e == ri) {
      n.update(val);
      return;
    }
    
    n.push_lazy(T[n.son[0]], T[n.son[1]]);
    
    update(le, min(T[n.son[0]].e, ri), val, n.son[0]);
    update(max(T[n.son[1]].s, le), ri, val, n.son[1]);
    n.merge(T[n.son[0]], T[n.son[1]]);
  }

  Node query(int le, int ri, int u = 0) {
    Node &n = T[u];
    if (n.e <= le || n.s >= ri) return Node::identity();
    if (n.s == le && n.e == ri) return n;

    n.push_lazy(T[n.son[0]], T[n.son[1]]);
    
    Node r1, r2, r3;
    r1 = query(le, min(T[n.son[0]].e, ri), n.son[0]);
    r2 = query(max(T[n.son[1]].s, le), ri, n.son[1]);
    r3.merge(r1, r2);
    return r3;
  }
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  while (cin >> n) {
    vi vec(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
      cin >> vec[i];
    }
    n += 2;
    
    SegmentTree<StNodeStairRi> st(n), st_inv(n);
    
    for (int i = 0; i < n; ++i) {
      const int val = vec[i];
      
      int ri_i = i + 1, ri_j = n - 1;
      if (ri_i <= ri_j) {
        StNodeStairRi upd;
        upd.val = val + 1;
        upd.s = ri_i, upd.e = ri_j + 1;
        st.update(upd.s, upd.e, upd);
      }
      
      int le_j = i - 1, le_i = 0;
      if (le_i <= le_j) {
        le_i = n - 1 - le_i;
        le_j = n - 1 - le_j;
        
        StNodeStairRi upd;
        upd.val = val + 1;
        upd.s = le_j, upd.e = le_i + 1;
        st_inv.update(upd.s, upd.e, upd);
      }
    }
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      const int j = n - 1 - i;
      int val = vec[i];
      val = min(val, st.query(i, i + 1).val);
      val = min(val, st_inv.query(j, j + 1).val);
      ans = max(ans, val);
    }
    
    cout << ans << endl;
  }
  
  return 0;
}
