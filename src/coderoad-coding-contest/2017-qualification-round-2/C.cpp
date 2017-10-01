// http://ccc.contest.codeforces.com/group/sqatZBP56w/contest/216136/problem/C

#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
int dp[100025][10][10], K;

int f(int n, int a, int b) {
  if (a == K+1 || b == K+1) return 0;
  if (n == 0) return 1;
  if (dp[n][a][b] != -1) return dp[n][a][b];
  
  int res1 = f(n-1, a+1, max(b-1, 0));
  int res2 = f(n-1, max(a-1, 0), b+1);
  int ans = res1 + res2;
  if (ans >= inf) ans -= inf;
  
  return dp[n][a][b] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  while (cin >> n >> K) {
    memset(dp, -1, sizeof dp);
    cout << f(n, 0, 0) << endl;
  }
  
  return 0;
}
