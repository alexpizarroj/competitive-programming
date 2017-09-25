#include <bits\stdc++.h>
using namespace std;

int main()
{
  // Fast IO
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n, m;
  while (cin >> n >> m)
  {
    int ans = 2*n;
    for(int y = 0; n >= 2*y; y++)
    {
      int x = n - 2*y;
      int cand = x + y;
      if (cand % m == 0)
      {
        ans = min(ans, cand);
      }
    }
    cout << (ans == 2*n ? -1 : ans) << '\n';
  }

  return 0;
}
