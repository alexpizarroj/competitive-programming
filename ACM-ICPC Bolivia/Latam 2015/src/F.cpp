#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using vi = vector<int>;
using vii = vector<ii>;
const int inf = 1000000007;

template <typename T>
class RangedFenwickTree {
 public:
  RangedFenwickTree() {}

  RangedFenwickTree(unsigned int n) { Init(n); }

  T Query(int at) const {
    T mul = 0, add = 0;
    int start = at;
    while (at >= 0) {
      mul += dataMul[at];
      add += dataAdd[at];
      at = (at & (at + 1)) - 1;
    }
    return mul * start + add;
  }

  T QueryInterval(int x, int y) const { return Query(y) - Query(x - 1); }

  void Update(int x, int y, T delta) {
    InternalUpdate(x, delta, -delta * (x - 1));
    if (y + 1 < (int)this->size()) InternalUpdate(y + 1, -delta, delta * y);
  }

  unsigned int size() const { return dataMul.size(); }

  void Init(unsigned int n) {
    dataMul.assign(n, 0);
    dataAdd.assign(n, 0);
  }

  vector<T> dataMul, dataAdd;

 private:
  void InternalUpdate(int x, T mul, T add) {
    for (int i = x; i < (int)this->size(); i = (i | (i + 1))) {
      dataMul[i] += mul;
      dataAdd[i] += add;
    }
  }
};

template<class T>
void uniquify(vector<T>& vec) {
  sort(begin(vec), end(vec));

  auto it = unique(begin(vec), end(vec));

  vec.erase(it, end(vec));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int p, v;
  while (cin >> p >> v) {
    // Read the points
    vii pt(p);
    for (int i = 0; i < p; ++i) {
      cin >> pt[i].first >> pt[i].second;
    }

    // Recover the polygon vertices
    vi xx, yy;
    xx.reserve(v);
    yy.reserve(v);
    
    vii vers(v);

    for (int i = 0; i < v; ++i) {
      int &x = vers[i].first, &y = vers[i].second;
      cin >> x >> y;
      xx.push_back(x);
      yy.push_back(y);
    }

    // Get all the different x and y coordinates from the segments
    uniquify(xx);
    uniquify(yy);

    const int n_x_buckets = 2 * xx.size() - 1;

    // This function will place an x value into a bucket of the x-axis
    auto bucketize_x = [&xx](int x) {
      if (x < xx[0] || x > xx.back()) return -1;
      
      auto it = lower_bound(begin(xx), end(xx), x);
      int idx = distance(begin(xx), it) * 2;
      if (x != *it) idx -= 1;
      
      return idx;
    };

    // Place each point in its corresponding y-bucket
    vector<vii> points_on_y_bucket((int)yy.size(), vii());

    for (int i = 0; i < p; ++i) {
      int y = pt[i].second;
      if (y <= yy[0] || y >= yy.back()) continue;
      
      auto it = lower_bound(begin(yy), end(yy), y);
      int idx = distance(begin(yy), it);
      if (*it != y) idx -= 1;
      y = idx;

      const int x = pt[i].first;
      if (x == xx[0] || x == xx.back()) continue;

      const int bu = bucketize_x(x);
      if (bu == -1) continue;

      auto val = ii(bu, i + 1);
      points_on_y_bucket[y].push_back(val);
    }

    // Recover the x-aligned segments and sort them by their height (y)
    vector<iii> sg(v / 2);
    for (int i = 0; i < v; ++i) {
      int x0 = vers[i].first, y0 = vers[i].second;
      int x = vers[(i + 1) % v].first, y = vers[(i + 1) % v].second;

      if (y0 != y) continue;
      
      int a = x0, b = x;
      if (a > b) swap(a, b);
      sg[i / 2]= {y, ii(bucketize_x(a), bucketize_x(b) - 1)};
    }
    
    sort(begin(sg), end(sg), [](const iii& a, const iii& b) {
      return a.first < b.first;
    });

    // Solve it!
    long long ans = (long long)p * (p + 1) / 2;
    RangedFenwickTree<long long> rft(n_x_buckets);

    int cur = 0, zone = sg[0].first, ylevel = 0;
    while (true) {
      // Update the covered x-ranges
      for (; cur < (int)sg.size() && sg[cur].first == zone; ++cur) {
        rft.Update(sg[cur].second.first, sg[cur].second.second, 1);
      }

      // Count the points covered
      for (const auto& cand : points_on_y_bucket[ylevel]) {
        auto res = rft.QueryInterval(cand.first, cand.first);
        if (res % 2 == 1) {
          ans -= cand.second;
        }
      }

      if (cur == (int)sg.size()) break;
      zone = sg[cur].first;
      ylevel += 1;
    }

    // Take your answer and don't come back, you bastard
    cout << ans << endl;
  }

  return 0;
}
