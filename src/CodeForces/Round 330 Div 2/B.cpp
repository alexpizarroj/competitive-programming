#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using vi = vector<int>;
using ii = pair<int, int>;

int cnt_div(int x, int top) {
  assert(top >= 0);
  return 1 + (top / x);
}

int pow(int x, int b) {
  int res = 1;
  for (int i = 0; i < b; ++i) {
    res *= 10;
  }
  return res;
}

int count_odds(int a, int b, int k) {
  const int top = pow(10, k) - 1;
  int t1 = cnt_div(a, top);

  const int var = (b * pow(10, k - 1)) % a;
  const int var2 = (a - var) % a;
  const int top2 = pow(10, k - 1) - 1;
  int t2 = 0;
  if (top2 >= var2) t2 = cnt_div(a, top2 - var2);
  
  return t1 - t2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, k;
  while (cin >> n >> k) {
    const int m = n / k;
    vi a(m), b(m);
    for (int i = 0; i < m; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
      cin >> b[i];
    }
    
    long long result = 1;
    for (int i = 0; i < m; ++i) {
      result *= count_odds(a[i], b[i], k);
      result %= inf;
    }
    cout << result << endl;
  }
  
  return 0;
}
