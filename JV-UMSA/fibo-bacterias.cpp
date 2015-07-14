#include <bits/stdc++.h>
using namespace std;

string big_add(const string& a, const string& b) {
  int LA = a.size(), LB = b.size(), L = max(LA, LB), carry = 0;

  string x = string(L, '0');

  while (L--) {
    LA--;
    LB--;

    if (LA >= 0) carry += a[LA] - '0';
    if (LB >= 0) carry += b[LB] - '0';

    if (carry < 10)
      x[L] = '0' + carry, carry = 0;
    else
      x[L] = '0' + carry - 10, carry = 1;
  }

  if (carry) x = '1' + x;
  return x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  vector<string> fib(200);
  fib[0] = fib[1] = "1";
  for (int i = 2; i < 200; i++) {
    fib[i] = big_add(fib[i - 1], fib [i - 2]);
  }
  
  int tc;
  cin >> tc;
  
  for (int i = 0; i < tc; i++) {
    int n;
    cin >> n;
    cout << fib[n - 1] << '\n';
  }
  
  return 0;
}
