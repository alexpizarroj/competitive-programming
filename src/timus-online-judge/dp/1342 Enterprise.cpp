#include <bits\stdc++.h>
using namespace std;

const double inf = 1e12;
typedef pair<double, double> dd;

struct Workshop
{
  int maxp;
  double cost0, cost1, delta;
};
double dp[1005][1005];

int main()
{
  // Fast IO
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n, m;
  while (cin >> n >> m)
  {
    // Workshops processing + maxp_sum vector setup
    vector<Workshop> ws(n+1);
    vector<int> maxp_sum(n+1);
    maxp_sum[0] = 0;
    for(int i = 1; i <= n; i++)
    {
      cin >> ws[i].maxp >> ws[i].cost0 >> ws[i].cost1;
      ws[i].delta = 0;
      if (ws[i].maxp >= 2)
        ws[i].delta = (ws[i].cost1 - ws[i].cost0) / (ws[i].maxp - 1);
      maxp_sum[i] = maxp_sum[i-1] + ws[i].maxp;
    }

    // Production adjustment according to the workshops
    if (maxp_sum.back() < m)
    {
      m = maxp_sum.back();
      cout << "Maximum possible amount: " << m << '\n';
    }

    // Base case
    for(int i = 0; i <= n; i++)
      dp[i][0] = 0;

    // DP solution
    for(int i = 1; i <= n; i++)
    {
      for(int j = 1; j <= m; j++)
      {
        const int min_prod = max(0, j - maxp_sum[i-1]);
        const int max_prod = min(j, ws[i].maxp);
        dp[i][j] = inf;
        for(int prod = min_prod; prod <= max_prod; prod++)
        {
          double cand = dp[i-1][j-prod];
          if (prod >= 1)
          {
            double last = ws[i].cost0 + (prod-1)*ws[i].delta;
            cand += ((ws[i].cost0 + last) * prod) / 2;
          }
          if (dp[i][j] > cand)
          {
            dp[i][j] = cand;
          }
        }
      }
    }

    // DP output
    cout << fixed << setprecision(2) << "Minimum possible cost: "
      << dp[n][m] << '\n';
  }

  return 0;
}
