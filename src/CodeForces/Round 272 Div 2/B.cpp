#include <bits\stdc++.h>
using namespace std;

int main()
{
  // Fast IO
  ios_base::sync_with_stdio(0); cin.tie(0);

  int fact[11];
  fact[0] = 1;
  for(int i = 1; i <= 10; i++)
  {
    fact[i] = fact[i-1] * i;
  }

  string s1, s2;
  while (cin >> s1 >> s2)
  {
    int p1, n1, p2, n2, un;
    int len = s1.size();

    p1 = n1 = un = p2 = n2 = 0;
    for(int i = 0; i < len; i++)
    {
      // s1
      if (s1[i] == '+')
        p1 += 1;
      else
        n1 += 1;
      // s2
      if (s2[i] == '+')
        p2 += 1;
      else if (s2[i] == '-')
        n2 += 1;
      else
        un += 1;
    }

    double ans = 0;
    if (p2 <= p1 && n2 <= n1)
    {
      int n = un;
      int k = p1 - p2;
      double comb = fact[n];
      comb /= fact[k];
      comb /= fact[n-k];
      ans = comb * pow(0.5, n);
    }
    cout << fixed << setprecision(9) << ans << '\n';
  }

  return 0;
}
