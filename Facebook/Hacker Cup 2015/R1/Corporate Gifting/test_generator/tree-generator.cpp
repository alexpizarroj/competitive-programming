/*
 * Generator of random labered trees.
 *
 * Description of the input arguments:
 *   argv[1] -> number of tree nodes; should be a positive integer >= 3
 *   argv[i] for all 'i' greater than 1 -> value to influence the random seed
 */

#include "testlib.h"
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <cassert>
using namespace std;

/*
   Generates a random labeled tree of size 'tsize'.
   
   The tree is returned in an adjacency list representation
   with vertices from 1 to N.
   
   That is, size(adj_list) = tsize + 1, because it skips the
   label 0 (zero position).
*/
vector<vector<int>> get_random_tree(int tsize) {
  assert(tsize >= 3);

  vector<int> s(tsize - 2);
  for (int i = 0; i < (int)s.size(); i++) {
    s[i] = rnd.next(1, tsize);
  }

  const int n = s.size();
  vector<vector<int>> T(n + 3, vector<int>());

  vector<int> deg(n + 3, 1);
  for (int x : s) {
    deg[x] += 1;
  }

  set<pair<int, int>> st;
  for (int i = 1; i <= n + 2; i++) {
    st.insert(make_pair(deg[i], i));
  }

  for (int i = 0; i < n; i++) {
    int u = st.begin()->second;
    int v = s[i];
    assert(deg[u] == 1);

    T[u].push_back(v);
    T[v].push_back(u);

    deg[u] -= 1;
    st.erase(st.begin());
    st.erase(make_pair(deg[v], v));
    if (deg[v] > 1) {
      st.insert(make_pair(deg[v] - 1, v));
    }
    deg[v] -= 1;
  }

  int t0 = 0, t1 = 0;
  for (int i = 1; i <= n + 2; i++) {
    if (deg[i] == 1) {
      if (t0 == 0) {
        t0 = i;
      } else {
        t1 = i;
        break;
      }
    }
  }

  deg[t0] -= 1;
  deg[t1] -= 1;
  T[t0].push_back(t1);
  T[t1].push_back(t0);

  return move(T);
}

/*
   Generates a random labeled tree of size 'n'.
   
   The tree is returned in a parent list representation with
   vertices from 1 to N.
   
   That is, size(parent_list) = n + 1, because it skips the
   label 0 (zero position).
*/
vector<int> get_random_tree_prepr(int n) {
  auto T = get_random_tree(n);
  vector<int> parent(n + 1, -1);
  queue<int> q;

  q.push(1);
  while (!q.empty()) {
    const int u = q.front();
    q.pop();

    for (int i = 0; i < (int)T[u].size(); i++) {
      const int v = T[u][i];
      if (parent[u] == v) {
        continue;
      }

      parent[v] = u;
      q.push(v);
    }
  }

  return parent;
}

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);

  if (argc < 2) {
    cerr << "Incorrect number of arguments" << endl;
    return 0;
  }

  int n;
  if (sscanf(argv[1], "%d", &n) != 1) {
    cerr << "Invalid argument" << endl;
    return 0;
  }

  if (n < 3) {
    cerr << "The number of tree nodes should be >= 3" << endl;
    return 0;
  }

  vector<int> tree = get_random_tree_prepr(n);

  cout << n << '\n';
  for (int i = 1; i <= n; i++) {
    if (i > 1) cout << " ";
    cout << tree[i];
  }
  cout << '\n';

  return 0;
}
