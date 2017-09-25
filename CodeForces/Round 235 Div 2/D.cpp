#include <bits\stdc++.h>
using namespace std;

string s;
int lsbpos[2097152], powerMod[10][20], n, m;
long long dp[300000][105];

long long f(int mask, int ac)
{ 
  if (mask == 0)
    return (ac == 0 ? 1 : 0);
  if (dp[mask][ac] != -1)
    return dp[mask][ac];

  int next_pos = __builtin_popcount(mask) - 1;
  long long ans = 0;
  for(int i = 0; i < n; i++)
  {
    if (((mask >> i) & 1) == false)
      continue;
    // DP propagation
    const int value = s[i] - '0';
    int new_mask = mask & (~(1<<i));
    int new_ac = (ac + powerMod[value][next_pos]) % m;
    ans += f(new_mask, new_ac);
    // Position update
    int j = i + 1;
    while (j < n && (((mask >> j) & 1) == false || s[j] == s[i]))
      j += 1;
    i = j - 1;
  }
  return dp[mask][ac] = ans;
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  for(int i = 0; i <= 20; i++)
    lsbpos[1<<i] = i;

  while (cin >> s >> m)
  {
    n = s.size();
    for(int i = 0; i <= 9; i++)
    {
      powerMod[i][0] = (i % m);
      for(int j = 1; j < n; j++)
        powerMod[i][j] = (powerMod[i][j-1] * 10) % m;
    }
    sort(begin(s), end(s), greater<int>());
    memset(dp, -1, sizeof dp);

    long long ans = 0;
    for(int i = 0; i < n && s[i] != '0'; i++)
    {
      const int value = s[i] - '0';
      int mask = ((1<<n) - 1) & (~(1<<i));
      int ac = powerMod[value][n-1];
      ans += f(mask, ac);
      // Position update
      int j = i;
      while (j < n && s[j] == s[i])
        j += 1;
      i = j - 1;
    }
    cout << ans << endl;
  }

  return 0;
}
