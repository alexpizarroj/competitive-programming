#include <bits/stdc++.h>
using namespace std;

//  1 ->  0
//  i ->  1
//  j ->  2
//  k ->  3
// -1 ->  4
// -i ->  5
// -j ->  6
// -k ->  7
const int ki = 1, kj = 2, kk = 3;
const int kMultTable[8][8] = 
  {
    {0, 1, 2, 3, 4, 5, 6, 7},
    {1, 4, 3, 6, 5, 0, 7, 2},
    {2, 7, 4, 1, 6, 3, 0, 5},
    {3, 2, 5, 4, 7, 6, 1, 0},
    {4, 5, 6, 7, 0, 1, 2, 3},
    {5, 0, 7, 2, 1, 4, 3, 6},
    {6, 3, 0, 5, 2, 7, 4, 1},
    {7, 6, 1, 0, 3, 2, 5, 4}
  };
int dp[10005][10005];

bool solve(long long X, const string &s)
{
  const int len = X * (int)s.size();
  if (len < 3)
  {
    return false;
  }
  
  // Get the string we're gonna work on
  string ss;
  ss.reserve(len);
  for(int i = 0; i < X; i++)
  {
    ss += s;
  }
  
  // Base cases
  memset(dp, -1, sizeof dp);
  for(int i = 0; i < len; i++)
  {
    dp[1][i] = (ss[i] - 'i' + 1);
  }
  
  // General cases
  for(int i = 2; i <= len; i++)
  {
    for(int j = 0; j + i <= len; j++)
    {
      const int lhs = dp[i - 1][j];
      assert(lhs >= 0);
      
      const int rhs = dp[1][j + i - 1];
      assert(rhs >= 0);
      
      dp[i][j] = kMultTable[lhs][rhs];
    }
  }
  
  // Find the answer!
  for(int i = 1; i < len - 1; i++)
  {
    for(int j = i + 1; j < len; j++)
    {
      bool isI = (dp[i][0] == 1);
      bool isJ = (dp[j - i][i] == 2);
      bool isK = (dp[len - j][j] == 3);
      if (isI && isJ && isK)
      {
        return true;
      }
    }
  }
  
  return false;
}

int main()
{
  for(int i = 0; i < 8; i++)
  {
    int cnt = 0, next = i;
    do
    {
      next = kMultTable[next][i];
      cnt += 1;
    } while (next != i);
    cout << i << " -> " << cnt << '\n';
  }
  
  
  int T;
  cin >> T;
  
  for(int test = 1; test <= T; test++)
  {
    long long X;
    cin >> X >> X;
    
    string s;
    cin >> s;
    
    string ans = solve(X, s) ? "YES" : "NO";
    cout << "Case #" << test << ": " << ans << '\n';
  }

  return 0;
}