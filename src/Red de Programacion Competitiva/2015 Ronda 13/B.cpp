#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using vi = vector<int>;
using ii = pair<int, int>;

struct Sensor {
  int x, y, r;
};

struct UnionFind {
  vector<int> pset, set_size;
  int disjointSetsSize;

  void initSet(int N) {
    pset.assign(N, 0);
    set_size.assign(N, 1);
    disjointSetsSize = N;
    for (int i = 0; i < N; i++) pset[i] = i;
  }

  int findSet(int i) {
    return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
  }

  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      set_size[findSet(j)] += set_size[findSet(i)];
      pset[findSet(i)] = findSet(j);
      disjointSetsSize--;
    }
  }

  int numDisjointsSets() { return disjointSetsSize; }

  int sizeOfSet(int i) { return set_size[findSet(i)]; }
};

bool overlap(const Sensor& a, const Sensor& b) {
  int x = a.x - b.x, y = a.y - b.y, sum = a.r + b.r;
  x *= x, y *= y, sum *= sum;
  return (x + y) <= sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  while (cin >> n) {
    vector<Sensor> ss;
    for (int i = 0; i < n; ++i) {
      int x, y, r;
      cin >> x >> y >> r;
      ss.push_back((Sensor){x, y, r});
    }

    const int m = n + 2;
    const int kLeft = m - 2, kRight = m - 1;

    int result = 0;
    UnionFind uf;
    uf.initSet(m);

    for (int k = 1; k <= n; ++k) {
      // Connect with the walls
      if (ss[k - 1].x - ss[k - 1].r <= 0) {
        uf.unionSet(k - 1, kLeft);
        // cout << "Built left" << endl;
      }

      if (ss[k - 1].x + ss[k - 1].r >= 200) {
        uf.unionSet(k - 1, kRight);
        // cout << "Built right" << endl;
      }

      // Connect with the other sensors
      for (int i = 0; i < k - 1; ++i) {
        if (overlap(ss[i], ss[k - 1])) {
          uf.unionSet(i, k - 1);
        }
      }

      // We good?
      if (uf.isSameSet(kLeft, kRight)) break;
      result = k;
    }

    cout << result << endl;
  }

  return 0;
}
