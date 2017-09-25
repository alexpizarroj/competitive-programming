/*
x_t = (T_0 - T_b) / (T_a - T_b)

x_2 = (65.4321 - 99.9) / (50 - 99.9)
x_3 = (99.9000 - 99.7000) / (99.8999 - 99.7000)
*/
#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
const double finf = (double)inf;

double solve(double r, double t, double vol, double tmp) {
  if (t != tmp) {
    return finf;
  }

  double result = vol / r;
  return result;
}

double solve(double r1, double t1, double r2, double t2, double vol,
             double tmp) {
  double x;

  if (t1 != t2) {
    x = (tmp - t2) / (t1 - t2);
  } else if (tmp == t1) {
    x = r1 / (r1 + r2);
  } else {
    x = finf;
  }

  if (x < 0 || x > 1) {
    return finf;
  }

  double time1 = (vol * x) / r1;
  double time2 = (vol * (1 - x)) / r2;

  double result = max(time1, time2);
  return result;
}

int main() {
  int tc;
  cin >> tc;

  for (int tt = 1; tt <= tc; tt++) {
    cout << "Case #" << tt << ": ";

    int n;
    cin >> n;

    double vol, tmp;
    cin >> vol >> tmp;

    double ans = finf;

    if (n == 1) {
      double r, t;
      cin >> r >> t;
      ans = solve(r, t, vol, tmp);
    } else {
      double r1, t1;
      cin >> r1 >> t1;

      double r2, t2;
      cin >> r2 >> t2;

      ans = min(solve(r1, t1, vol, tmp), solve(r2, t2, vol, tmp));
      ans = min(ans, solve(r1, t1, r2, t2, vol, tmp));
    }

    if (ans == finf) {
      cout << "IMPOSSIBLE\n";
    } else {
      cout << fixed << setprecision(9) << ans << '\n';
    }
  }

  return 0;
}
