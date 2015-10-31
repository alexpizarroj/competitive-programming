#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using vi = vector<int>;
using ii = pair<int, int>;

long long gcd(long long a, long long b) {
  long long c;
  while (b != 0) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long t, w, b;
  while (cin >> t >> w >> b) {
    long long p = 0, q = t;

    if (w == b) {
      p = t;
    } else {
      // Initial tie range
      {
        auto a = min(w, b) - 1;
        p += min(a, t);
      }

      // Non-initial tie ranges
      long long ignore_from_here_mult = t / b;
      if (b * ignore_from_here_mult <= t) {
        ignore_from_here_mult += 1;
      }

      long long g = gcd(w, b), mult = w / g;
      if (mult < ignore_from_here_mult) {
        // mcm(w, b) <= t

        auto mcm = (w / g) * b;
        auto n_ranges_start = t / mcm;
        auto range_len = min(w, b);
        assert(n_ranges_start >= 1);

        p += (n_ranges_start - 1) * range_len;

        using ull = unsigned long long;
        ull last_start = n_ranges_start * mcm;
        ull last_end = last_start + range_len - 1;
        p += min((ull)t, last_end) - last_start + 1;
      }
    }

    long long d = gcd(p, q);
    p /= d, q /= d;
    cout << p << '/' << q << endl;
  }

  return 0;
}
