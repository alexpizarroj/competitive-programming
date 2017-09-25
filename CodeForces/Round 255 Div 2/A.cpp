#include <bits\stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  int p, n;
  while (cin >> p >> n)
  {
    vector<bool> used(p, false);
    int ans = -1;
    for(int i = 1; i <= n; i++)
    {
      int value;
      cin >> value;
      if (ans != -1)
        continue;

      int bucket = value % p;
      if (used[bucket])
        ans = i;
      else
        used[bucket] = true;
    }
    cout << ans << endl;
  }
  
  return 0;
}
