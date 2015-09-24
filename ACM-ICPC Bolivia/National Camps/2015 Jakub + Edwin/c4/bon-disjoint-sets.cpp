#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
  int *pset = nullptr, sz;

  UnionFind() {}

  explicit UnionFind(int N) { initSet(N); }
  
  ~UnionFind() {
    if (pset != nullptr) {
      delete[] pset;
    }
  }

  void initSet(int N) {
    if (pset != nullptr) {
      delete[] pset;
    }
    
    sz = N;
    pset = new int[N];
    for (int i = 0; i < N; i++) pset[i] = i;
  }

  int findSet(int i) {
    return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
  }

  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  void unionSet(int i, int j) {
    i = findSet(i), j = findSet(j);
    if (i != j) {
      if (j < i) {
        swap(i, j);
      }
      pset[i] = j;
    }
  }

  int size() const { return sz; }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int m;
  cin >> m;

  vector<bool> is_vou(1000001, false);
  int max_vou = 0;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    is_vou[x] = true;
    max_vou = max(max_vou, x);
  }

  UnionFind* uf = new UnionFind[max_vou + 1];
  for (int i = 1; i <= max_vou; i++) {
    int cnt = max_vou / i;
    uf[i].initSet(cnt + 2);
  }

  const int kShortLimit = 32767;
  vector<short>* divisors = new vector<short>[max_vou + 1];
  for (int i = 1; i <= max_vou; i++) {
    for (int j = i; j <= max_vou; j += i) {
      int counter = j / i;
      if (counter > kShortLimit ||
          !binary_search(begin(divisors[j]), end(divisors[j]),
                         (short)counter)) {
        divisors[j].push_back((short)i);
      }
    }
  }

  int n;
  cin >> n;

  long long next = 1;
  vector<long long> ans;

  auto update = [&](int d, int mult) {
    int a = mult / d;
    uf[d].unionSet(a, a + 1);
  };

  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;

    int served = 0, mult = c;
    while (served < c) {
      bool skip = (c > max_vou);
      if (!skip) {
        int ret = uf[c].findSet(mult / c);
        if (ret == uf[c].size() - 1) {
          skip = true;
        } else {
          mult = ret * c;
        }
      }

      if (skip) {
        next += c - served;
        served = c;
        continue;
      }

      for (int d : divisors[mult]) {
        int d2 = mult / d;
        update(d, mult);
        if (d != d2) {
          update(d2, mult);
        }
      }

      if (is_vou[mult]) {
        ans.push_back(next);
      }
      served += 1, next += 1, mult += c;
    }
  }

  cout << ans.size() << '\n';
  for (long long x : ans) {
    cout << x << '\n';
  }

  delete[] divisors;
  delete[] uf;

  return 0;
}
