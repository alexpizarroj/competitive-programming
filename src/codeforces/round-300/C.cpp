#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  while (cin >> n >> m)
  {
    int ld = 0, lh = 0, ans = 0;
    bool ok = true;

    for(int i = 0; i < m; i++)
    {
      int d, h;
      cin >> d >> h;
      if (!ok)
      {
        continue;
      }

      // Trivial height
      ans = max(ans, h);

      // Pre first day max height
      if (i == 0)
      {
        ans = max(ans, d - 1 + h);
      }

      // Post last day max height
      if (i == m - 1)
      {
        ans = max(ans, n - d + h);
      }

      // In between days height
      if (i > 0)
      {
        const int maxvar = d - ld;
        const int to_reach = abs(h - lh);
        // Are these records consistent?
        if (to_reach > maxvar)
        {
          ok = false;
          continue;
        }
        // If they are, calc the max h
        int delta_h = (maxvar - to_reach) / 2;
        ans = max(ans, max(h, lh) + delta_h);
      }

      // Last record values saving
      ld = d;
      lh = h;
    }

    // Output
    if (ok)
    {
      cout << ans << '\n';
    }
    else
    {
      cout << "IMPOSSIBLE\n";
    }
  }

  return 0;
}