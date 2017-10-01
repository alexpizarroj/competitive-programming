#include <bits\stdc++.h>
using namespace std;

typedef long double Real;
Real dp[2][5005][2];

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n, s;
  while (cin >> n >> s)
  {
    assert(2*n <= s && s <= 3*n);

    int n_ones = s - 2*n;
    int cur = 0, prev = 1;
    for(int len = 1; len <= n; len++)
    {
      int n_ones_limit = min(len, n_ones);
      for(int y = 0; y <= n_ones_limit; y++)
      {
        int x = len - y;
        for(int t = 0; t < 2; t++)
        {
          if (len == 1)
          {
            dp[cur][y][t] = (y != t ? 1 : 0);
          }
          else
          {
            Real odds_0 = (Real)x / len;
            Real odds_1 = 1.0 - odds_0;
            int err_0 = (t != 0 ? 1 : 0);
            int err_1 = 1 - err_0;
            dp[cur][y][t] = 0;
            dp[cur][y][t] += odds_0 * (err_0 + dp[prev][y][0]);
            dp[cur][y][t] += odds_1 * (err_1 + dp[prev][y-1][1]);
          }
        }
      }
      swap(cur, prev);
    }
    cout << fixed << setprecision(5) << dp[prev][n_ones][1] << '\n';
  }

  return 0;
}
