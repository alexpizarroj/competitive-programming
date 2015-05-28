#include <bits/stdc++.h>
using namespace std;

template <int alphabet_size> struct TrieNode {
  int child[alphabet_size];

  TrieNode() { memset(child, 0, sizeof child); }
};

struct Trie {
  static const int msb_pos = 31;
  typedef TrieNode<2> TNode;
  vector<TNode> nodes;

  Trie() { nodes.push_back(TNode()); }

  int bit_at(int x, int i) {
    int result = ((x >> i) & 1);
    return result;
  }

  void add(int x) {
    int current = 0;

    for (int i = msb_pos; i >= 0; i--) {
      int next_child = bit_at(x, i);

      int next_node = nodes[current].child[next_child];
      if (next_node == 0) {
        next_node = nodes.size();
        nodes[current].child[next_child] = next_node;
        nodes.push_back(TNode());
      }
      current = next_node;
    }
  }

  int query(int x) {
    int result = 0, current = 0;

    for (int i = msb_pos; i >= 0; i--) {
      int next_child = bit_at(x, i);
      int couple = 1 - next_child;

      if (nodes[current].child[couple] == 0) {
        current = nodes[current].child[next_child];
      } else {
        result |= (1 << i);
        current = nodes[current].child[couple];
      }
    }

    return result;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tcases;
  cin >> tcases;

  for (int tc = 1; tc <= tcases; tc++) {
    int n;
    cin >> n;

    int result = 0, current_xor = 0;
    vector<int> prefixes;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;

      current_xor ^= x;
      prefixes.push_back(current_xor);

      result = max(result, current_xor);
    }

    Trie tt;
    for (int i = 0; i < n; i++) {
      tt.add(prefixes[i]);

      int cand = tt.query(prefixes[i]);
      result = max(result, cand);
    }

    cout << result << '\n';
  }

  return 0;
}
