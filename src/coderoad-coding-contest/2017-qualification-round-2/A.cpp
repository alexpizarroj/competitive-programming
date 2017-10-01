// http://ccc.contest.codeforces.com/group/sqatZBP56w/contest/216136/problem/A

#include <bits/stdc++.h>
using namespace std;

pair<long double, long double> findConstants(const vector<int>& x, const vector<long double>& y) {
  const int n = x.size();
  
  /*
  c1 = (sum(log(y_i)) from i=1 to n)
  c2 = N
  c3 = (sum(log(x_i)) from i=1 to n)
  c4 = (sum(log(x_i)*log(y_i)) from i=1 to n)
  c5 = (sum(log(x_i)^2) from i=1 to n)
  */
  long double c1=0, c2=n, c3=0, c4=0, c5=0;
  for (int i = 0; i < n; ++i) {
    long double xx = log(x[i]);
    long double yy = log(y[i]);
    c1 += yy;
    c3 += xx;
    c4 += xx * yy;
    c5 += xx * xx;
  }
  
  long double t1 = c3*c3-c2*c5;
  long double b = (c1*c3-c2*c4)/t1;
  long double a = exp((c3*c4-c1*c5)/t1);
  
  return make_pair(a, b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  while (cin >> n) {
    vector<int> x(n);
    vector<long double> y(n);
    for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i];
    }
    
    int q;
    cin >> q;
    
    string product;
    cin >> product;
    
    pair<long double, long double> ret = findConstants(x, y);
    long double ans = ret.first * pow(q, ret.second);
    
    cout << product << " " << fixed << setprecision(2) << ans << endl;
  }
  
  return 0;
}
