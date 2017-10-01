#include <bits\stdc++.h>
using namespace std;

// Let A = 0, B = 1, for the last param of the dp state
unsigned long long dp[2][45][45][45][2];

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n, k;
  while (cin >> n >> k)
  {
    string loco;
    cin >> loco;
    int t0 = (loco[1] == 'A' ? 1 : 0), t1 = (loco[0] == 'A' ? 1 : 0);

    int n_car[4] = {0, 0, 0, 0};
    for(int i = 0; i < n; i++)
    {
      string car;
      cin >> car;
      if (car == "AA")
        n_car[0] += 1;
      else if (car == "AB")
        n_car[1] += 1;
      else if (car == "BA")
        n_car[2] += 1;
      else if (car == "BB")
        n_car[3] += 1;
    }

    int cur = 0, prev = 1;
    for(int len = n - k + 1; len <= n; len++)
    {
      for(int a = 0; a <= len; a++)
        for(int b = 0; b <= len-a; b++)
          for(int c = 0; c <= len-a-b; c++)
          {
            int d = len - a - b - c;
            for(int t = 0; t < 2; t++)
            {
              unsigned long long &st = dp[cur][b][c][d][t];
              if (len == n - k + 1)
              {
                if (t0 == 1 && t == 1)
                  st = (a > 0 ? 1 : 0);
                else if (t0 == 1 && t == 0)
                  st = (b > 0 ? 1 : 0);
                else if (t0 == 0 && t == 1)
                  st = (c > 0 ? 1 : 0);
                else if (t0 == 0 && t == 0)
                  st = (d > 0 ? 1 : 0);
              }
              else
              {
                st = 0;
                if (t == 1)
                {
                  if (a > 0)
                    st += dp[prev][b][c][d][1];
                  if (c > 0)
                    st += dp[prev][b][c-1][d][0];
                }
                else
                {
                  if (b > 0)
                    st += dp[prev][b-1][c][d][1];
                  if (d > 0)
                    st += dp[prev][b][c][d-1][0];
                }
              }
            }
          }
      swap(cur, prev);
    }

    unsigned long long ans = dp[prev][n_car[1]][n_car[2]][n_car[3]][t1];
    if (ans > 0)
    {
      cout << "YES\n";
      cout << ans << '\n';
    }
    else
      cout << "NO\n";
  }

  return 0;
}
