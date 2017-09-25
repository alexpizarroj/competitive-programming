#include <bits/stdc++.h>
using namespace std;

int main() {
  double a, b;
  while (cin >> a >> b) {
    double result = (a * 3.5 + b * 7.5) / 11.0;
    cout << "MEDIA = " << fixed << setprecision(5) << result << '\n';
  }
  return 0;
}
