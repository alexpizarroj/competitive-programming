#include <functional>
#include <iostream>
#include <vector>
using namespace std;

const int kLazyPreserveAll = 0;
const int kLazyInvertAll = 1;
const int kLazySetAllBuccaneer = 2;
const int kLazySetAllBarbary = 3;

int apply_lazy_op(int num_pirates, int num_buccaneers, int lazy_op) {
  if (lazy_op == kLazyInvertAll) return num_pirates - num_buccaneers;

  if (lazy_op == kLazySetAllBuccaneer) return num_pirates;

  if (lazy_op == kLazySetAllBarbary) return 0;

  return num_buccaneers;
}

int compose_lazy_ops(int new_lazy_op, int prev_lazy_op) {
  if (new_lazy_op == kLazyPreserveAll) return prev_lazy_op;

  if (new_lazy_op == kLazyInvertAll) {
    if (prev_lazy_op == kLazyInvertAll) return kLazyPreserveAll;
    if (prev_lazy_op == kLazySetAllBuccaneer) return kLazySetAllBarbary;
    if (prev_lazy_op == kLazySetAllBarbary) return kLazySetAllBuccaneer;
    return kLazyInvertAll;
  }

  return new_lazy_op;
}

struct StNode {
  using NodeType = StNode;
  int num_buccaneers;
  int lazy;

  StNode() {}

  StNode(int num_buccaneers, int lazy) {
    this->num_buccaneers = num_buccaneers;
    this->lazy = lazy;
  }

  // Used, while creating the tree, to update the Node content according to
  // the value given by the ValueProvider
  void set(const NodeType& from) {
    num_buccaneers = from.num_buccaneers;
    lazy = identity().lazy;
  }

  // Updates the Node content to store the result of the 'merge' operation
  // applied on the children.
  // The tree will always call push_lazy() on the Node *before* calling merge()
  void merge(const NodeType& le, const NodeType& ri) {
    num_buccaneers = le.num_buccaneers + ri.num_buccaneers;
    lazy = identity().lazy;
  }

  // Used to update the Node content in a tree update command
  void update(const NodeType& from) {
    num_buccaneers = apply_lazy_op(e - s, num_buccaneers, from.lazy);
    lazy = compose_lazy_ops(from.lazy, lazy);
  }

  // Pushes any pending lazy updates to children
  void push_lazy(NodeType& le, NodeType& ri) {
    if (lazy == identity().lazy) return;

    le.num_buccaneers = apply_lazy_op(le.e - le.s, le.num_buccaneers, lazy);
    le.lazy = compose_lazy_ops(lazy, le.lazy);

    ri.num_buccaneers = apply_lazy_op(ri.e - ri.s, ri.num_buccaneers, lazy);
    ri.lazy = compose_lazy_ops(lazy, ri.lazy);

    lazy = identity().lazy;
  }

  // This function should return a NodeType instance such that calling
  // Y.merge(X, identity()) or Y.merge(identity(), X) for any Node X with no
  // pending updates should make Y match X exactly.
  static NodeType identity() {
    static auto tmp = NodeType(0, kLazyPreserveAll);
    return tmp;
  }

  // Internal tree data
  int son[2];          // Children of this node
  int s = -1, e = -1;  // Interval [s, e), covered by this node
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

  void update(int le, int ri, const Node& val, int u = 0) {
    Node& n = T[u];
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
    Node& n = T[u];
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

string ReadAllPirates() {
  int m;
  cin >> m;

  string result;
  result.reserve(1024000);

  for (int i = 0; i < m; ++i) {
    int t;
    string teams;
    cin >> t >> teams;

    for (int j = 0; j < t; ++j) result.append(teams);
  }

  return result;
}

void AnswerQueries(const string& pirates) {
  SegmentTree<StNode> tree((int)pirates.size(), [&](int i) {
    return StNode(pirates[i] == '1' ? 1 : 0, kLazyPreserveAll);
  });

  int q, next_query_id = 1;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    string op;
    int a, b;
    cin >> op >> a >> b;
    b += 1;

    if (op == "F") {
      tree.update(a, b, StNode(0, kLazySetAllBuccaneer));

    } else if (op == "E") {
      tree.update(a, b, StNode(0, kLazySetAllBarbary));

    } else if (op == "I") {
      tree.update(a, b, StNode(0, kLazyInvertAll));

    } else if (op == "S") {
      cout << "Q" << (next_query_id++) << ": ";
      cout << tree.query(a, b).num_buccaneers << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  for (int tc = 1; tc <= T; ++tc) {
    cout << "Case " << tc << ":\n";
    string pirates = ReadAllPirates();
    AnswerQueries(pirates);
  }

  return 0;
}
