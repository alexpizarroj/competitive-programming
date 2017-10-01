// https://leetcode.com/contest/leetcode-weekly-contest-52/problems/knight-probability-in-chessboard/

#include <bits/stdc++.h>
using namespace std;

double dp[26][101][26][26];

class Solution {
public:
  double knightProbability(int N, int K, int r, int c) {
    for (int i1 = 0; i1 < 26; ++i1)
    for (int i2 = 0; i2 < 101; ++i2)
    for (int i3 = 0; i3 < 26; ++i3)
    for (int i4 = 0; i4 < 26; ++i4) {
      dp[i1][i2][i3][i4] = kUnsolved;
    }
    
    return f(N, K, r, c);
  }

private:
  const int mx[8] = {-2, -2,2,2,1,-1,1,-1};
  const int my[8] = {1, -1,1,-1,-2,-2,2,2};
  const int kUnsolved = -1;
  
  double f(int N, int K, int r, int c) {
    if (!inside(N, r, c)) return 0;
    
    if (dp[N][K][r][c] != kUnsolved) return dp[N][K][r][c];
    
    if (K == 0) return dp[N][K][r][c]=1;
    
    double ans = 0;
    for (int i = 0; i < 8; ++i) {
      int x = r+mx[i], y = c+my[i];
      ans += f(N, K-1, x, y);
    }
    
    return dp[N][K][r][c]=ans/8;
  }
  
  bool inside(int N, int r, int c) {
    return (0 <= r && r < N && 0 <= c && c < N);
  }
};

void test1() {
  Solution s;
  cout << s.knightProbability(3, 2, 0, 0) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  test1();
  
  return 0;
}
