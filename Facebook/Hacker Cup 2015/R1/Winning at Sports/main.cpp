#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
int x, y, total, dp[4005][2005];

int f1(const int remaining, const int yours)
{
  const int theirs = total - remaining - yours;
  int &res = dp[remaining][yours];
  if (res == -1)
  {
    long long tmp = 0;
    if (theirs < y && theirs + 1 < yours)
      tmp += f1(remaining - 1, yours);
    if (yours < x)
      tmp += f1(remaining - 1, yours + 1);
    res = (tmp % inf);
  }
  return res;
}

int Solve1()
{
  memset(dp, -1, sizeof dp);
  dp[0][x] = 1;
  return f1(total, 0);
}

int f2(const int remaining, const int yours)
{
  const int theirs = total - remaining - yours;
  int &res = dp[remaining][yours];
  if (res == -1)
  {
    long long tmp = 0;
    if (theirs < y)
    {
      if (yours < theirs)
        tmp += f2(remaining - 1, yours + 1);
      tmp += f2(remaining - 1, yours);
    }
    else
    {
      tmp += f2(remaining - 1, yours + 1);
    }
    res = (tmp % inf);
  }
  return res;
}

int Solve2()
{
  memset(dp, -1, sizeof dp);
  dp[0][x] = 1;
  return f2(total, 0);
}

int main()
{
  int test_cases;
  scanf("%d", &test_cases);
  for(int tc = 1;  tc <= test_cases; tc++)
  {
    scanf("%d-%d", &x, &y);
    total = x + y;  

    int ans1 = Solve1();
    int ans2 = Solve2();
    printf("Case #%d: %d %d\n", tc, ans1, ans2);
  }
  
  return 0;
}
