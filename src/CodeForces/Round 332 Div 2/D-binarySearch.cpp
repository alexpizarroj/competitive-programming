#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using int64 = long long;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using vi = vector<int>;
using vii = vector<ii>;

const int64 kLimit = 1000000000000000000LL;

bool safe_mult(int64 a, int64 b, int64 &r) {
  if (b > kLimit / a) return false;
  r = a * b;
  return true;
}

int64 f(int64 n, int64 m) { // holds: m <= 1.5kk
  // partial result m * (m - 1) * (2 * m - 1) / 6;
  int64 t1 = m * (m - 1) * (2 * m - 1) / 6;
  if (t1 > kLimit) return kLimit + 1;

  // partial result m * (n - m + 1)
  int64 t2;
  if (!safe_mult(n - m + 1, m, t2)) return kLimit + 1;

  // partial result (n - m + 2) * (m * (m - 1)) / 2
  int64 t3;
  if (!safe_mult(n - m + 2, m * (m - 1) / 2, t3)) return kLimit + 1;

  return t1 + t2 + t3;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  const int maxmin = 1500000;

  int64 x;
  while (cin >> x) {
    vector<pair<int64, int64>> result;

    int64 last_hi = kLimit;
    for (int i = 1; i <= maxmin; ++i) {
      int64 lo = i, hi = last_hi;

      int64 tmpres = f(lo, lo);
      if (tmpres == x) {
        result.emplace_back(i, i);
      }
      if (tmpres >= x) break;

      while (hi - lo > 1) {
        int64 mid = lo + (hi - lo) / 2;
        if (f(mid, i) >= x) {
          hi = mid;
        } else {
          lo = mid;
        }
      }

      last_hi = hi;
      if (f(hi, i) == x) {
        result.emplace_back(hi, i);
        result.emplace_back(i, hi);
      }
    }

    sort(begin(result), end(result));
    cout << result.size() << '\n';
    for (auto&& p : result) {
      cout << p.first << " " << p.second << '\n';
    }
  }

  return 0;
}
