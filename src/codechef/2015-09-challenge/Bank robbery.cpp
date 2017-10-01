#include <iostream>
#include <iomanip>
using namespace std;

double power(double b, int e) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b, e - 1);
  double tmp = power(b, e / 2);
  return tmp * tmp;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  const double money = 1000000000;
  int tc;
  cin >> tc;
  
  for (int cas = 1; cas <= tc; ++cas) {
    int m;
    double p;
    cin >> m >> p;
    
    double f = (1 - power(-p, m)) / (1 + p);
    double a = money * f, b = money - a;
    cout << fixed << setprecision(5) << a << " " << b << '\n';
  }
  
  return 0;
}
