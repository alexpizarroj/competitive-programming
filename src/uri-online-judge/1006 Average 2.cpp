#include <bits/stdc++.h>
using namespace std;

int main() {
  double a, b, c;
  while (cin >> a >> b >> c) {
    double result = (a * 2 + b * 3 + c * 5) / 10.0;
    cout << "MEDIA = " << fixed << setprecision(1) << result << '\n';
  }
  return 0;
}
