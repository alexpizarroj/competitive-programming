#include <bits\stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n;
  while (cin >> n)
  {
    vector<int> vec(n);
    for(int i = 0; i < n; i++)
      cin >> vec[i];

    vector<int> dp(n);
    dp[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--)
    {
      if (vec[i] < vec[i+1])
        dp[i] = 1 + dp[i+1];
      else
        dp[i] = 1;
    }

    int ans = 1;
    for(int i = 0; i < n; i++)
    {
      // Option 1
      int candidate = dp[i];
      int j = i + dp[i];
      if (j < n)
      {
        candidate += 1;
        if (j + 1 < n && (vec[j - 1] + 1) < vec[j + 1])
          candidate += dp[j + 1];
      }
      ans = max(ans, candidate);
      // Option 2
      if (i + 1 < n)
      {
        candidate = 1 + dp[i + 1];
        ans = max(ans, candidate);
      }
      // Option 3
      if (dp[i] > 1)
      {
        candidate = dp[i];
        j = i + dp[i] - 1;
        if (j + 1 < n && (vec[j - 1] + 1) < vec[j + 1])
          candidate += dp[j + 1];
        ans = max(ans, candidate);
      }
    }

    cout << ans << endl;
  }
  
  return 0;
}
