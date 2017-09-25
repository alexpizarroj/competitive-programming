#include <bits\stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  const int inf = 1000000007;
  int a, b;
  while (cin >> a >> b)
  {
    long long ans = 0;
    for(int rem = 1; rem < b; rem++)
    {
      // Sum part coming from all numbers with remainder rem
      long long a1, an, n, r;
      r = ((long long)rem * b) % inf;
      a1 = (r + rem) % inf;
      n = a;
      an = (a1 + ((long long)(n-1) * r)) % inf;
      long long sum = (a1 + an) % inf;
      sum = (sum * n) % inf;
      sum = (sum * 500000004) % inf;
      // Answer update
      ans = (ans + sum) % inf;
    }
    cout << ans << '\n';
  }

  return 0;
}
