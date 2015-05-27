/*
** @author Alex Erick Pizarro Jimenez
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  int p, a, b, c, d, n;
  cin >> p >> a >> b >> c >> d >> n;

  vector<double> price;
  for(int k = 1; k <= n; k++) {
    double res = p * (sin(a * k + b) + cos(c * k + d) + 2);
    price.push_back(res);
  }

  double low = price.back(), ans = 0.0;
  for(int i = n - 1; i >= 0; i--) {
    double cand = (price[i] > low ? price[i] - low : 0.0);
    ans = max(ans, cand);

    low = min(price[i], low);
  }

  cout << fixed << setprecision(9) << ans << endl;

  return 0;
}
