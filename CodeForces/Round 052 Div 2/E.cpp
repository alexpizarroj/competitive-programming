#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using vi = vector<int>;
using ii = pair<int, int>;

struct Node {
  int s, e;       // Interval [s, e) is covered by this node
  int son[2];     // Children of this node
  int val;        // Max of the interval
  int lazy;       // Max value yet to set
};

struct SegmentTree {
  vector<Node> T;

  SegmentTree(const vector<int>& vec) {
    const int N = vec.size();
    
    Node n;
    n.s = 0, n.e = N;
    n.son[0] = n.son[1] = -1;
    n.val = n.lazy = -inf;

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
      n.lazy = val;
      n.val = max(n.val, val);
      return;
    }
    
    push_lazy(u);
    if (le < T[n.son[0]].e) {
      update(n.son[0], le, min(T[n.son[0]].e, ri), val);
      update(n.son[1], max(T[n.son[1]].s, le), ri, val);
    } else {
      update(n.son[1], max(T[n.son[1]].s, le), ri, val);
    }
    
    n.val = max(T[n.son[0]].val, T[n.son[1]].val);
  }

  void push_lazy(int u) {
    Node &n = T[u];
    if (n.lazy == -inf) return;

    for (int i = 0; i < 2; i++) {
      if (n.son[i] != -1) {
        Node &son = T[n.son[i]];
        son.lazy = n.lazy;
        son.val = max(son.val, n.lazy);
      }
    }
    n.lazy = -inf;
  }

  int query(int u, int le, int ri) {
    Node &n = T[u];
    if (n.e <= le || n.s >= ri) return -inf;

    if (n.s == le && n.e == ri) return n.val;

    push_lazy(u);
    int res = query(n.son[0], le, min(T[n.son[0]].e, ri));
    res = max(res, query(n.son[1], max(T[n.son[1]].s, le), ri));
    return res;
  }
};

struct Domino {
  int x, id, h;
  bool operator<(const Domino& rhs) const {
    return x > rhs.x;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  while (cin >> n) {
    vector<Domino> vec(n);
    for (int i = 0; i < n; ++i) {
      vec[i].id = i;
      cin >> vec[i].x >> vec[i].h;
    }
    sort(begin(vec), end(vec));
    
    SegmentTree st(n, -inf);
    vector<int> ans(n);
    
    st.update(0, 0, 1, vec[0].x + vec[0].h - 1);
    ans[vec[0].id] = 1;
    
    for (int i = 1; i < n; ++i) {
      const int drop_reach = vec[i].x + vec[i].h - 1;
      
      auto it1 = lower_bound(begin(vec), end(vec), (Domino){drop_reach, 0, 0});
      int pos1 = distance(begin(vec), it1);
      assert(pos1 <= i);
      
      assert(vec[pos1].x <= drop_reach);
      if (pos1 - 1 >= 0) {
        assert(vec[pos1 - 1].x > drop_reach);
      }
      
      const int reach = max(drop_reach, st.query(0, pos1, i));
      st.update(0, i, i + 1, reach);
      
      auto it2 = lower_bound(begin(vec), end(vec), (Domino){reach, 0, 0});
      int pos2 = distance(begin(vec), it2);
      assert(pos2 <= i);
      
      assert(vec[pos2].x <= reach);
      if (pos2 - 1 >= 0) {
        assert(vec[pos2 - 1].x > reach);
      }
      
      ans[vec[i].id] = i - pos2 + 1;
    }
    
    for (int i = 0; i < n; ++i) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
  
  return 0;
}
