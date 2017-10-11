#include <functional>
#include <iostream>
#include <vector>
using namespace std;

struct StNode {
  using NodeType = StNode;
  int range_ans;
  int prefix_len, prefix_val;
  int suffix_len, suffix_val;
  bool is_identity;

  StNode() { this->is_identity = false; }

  StNode(bool is_identity) { this->is_identity = is_identity; }

  void set(const NodeType& from) {
    range_ans = from.range_ans;
    prefix_len = from.prefix_len;
    prefix_val = from.prefix_val;
    suffix_len = from.suffix_len;
    suffix_val = from.suffix_val;
    is_identity = false;
  }

  void merge(const NodeType& le, const NodeType& ri) {
    if (le.is_identity) {
      this->set(ri);
      return;
    }

    if (ri.is_identity) {
      this->set(le);
      return;
    }

    range_ans = max(le.range_ans, ri.range_ans);
    if (le.suffix_val == ri.prefix_val) {
      int cand = le.suffix_len + ri.prefix_len;
      if (cand > range_ans) range_ans = cand;
    }

    prefix_val = le.prefix_val;
    prefix_len = le.prefix_len;
    if (le.prefix_len == le.e - le.s && le.prefix_val == ri.prefix_val) {
      prefix_len += ri.prefix_len;
    }

    suffix_val = ri.suffix_val;
    suffix_len = ri.suffix_len;
    if (ri.prefix_len == ri.e - ri.s && le.suffix_val == ri.suffix_val) {
      suffix_len += le.suffix_len;
    }

    is_identity = false;
  }

  static const NodeType identity() {
    static auto tmp = NodeType(true);
    return tmp;
  }

  int son[2] = {0};
  int s = -1, e = -1;
};

template <class Node>
struct SegmentTree {
  using ValueProvider = function<Node(int)>;
  vector<Node> T;

  SegmentTree(int n, const ValueProvider& vp) {
    Node nd;
    nd.son[0] = nd.son[1] = -1;
    nd.s = 0, nd.e = n;

    T.reserve(4 * n);
    T.emplace_back(std::move(nd));

    init(vp, 0);
  }

  void init(const ValueProvider& vp, int u) {
    Node& n = T[u];

    if (n.e - n.s == 1) {
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

  Node query(int le, int ri, int u = 0) {
    Node& n = T[u];
    if (n.e <= le || n.s >= ri) return Node::identity();
    if (n.s == le && n.e == ri) return n;

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
  while (cin >> n && n != 0) {
    int q;
    cin >> q;

    vector<int> values(n);
    for (int i = 0; i < n; ++i) cin >> values[i];

    SegmentTree<StNode> tree(n, [&](int i) {
      StNode node;
      node.range_ans = 1;
      node.prefix_len = node.suffix_len = 1;
      node.prefix_val = node.suffix_val = values[i];
      node.is_identity = false;
      return node;
    });

    for (int i = 0; i < q; ++i) {
      int a, b;
      cin >> a >> b;
      cout << tree.query(a - 1, b).range_ans << '\n';
    }
  }

  return 0;
}
