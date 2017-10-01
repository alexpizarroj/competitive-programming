// https://leetcode.com/contest/leetcode-weekly-contest-52/problems/knight-probability-in-chessboard/

#include <bits/stdc++.h>
using namespace std;

double dp[101][26][26];

class Solution {
public:
  double knightProbability(int N, int K, int r, int c) {
    this->N = N;
    
    for (int i1 = 0; i1 < 101; ++i1)
    for (int i2 = 0; i2 < 26; ++i2)
    for (int i3 = 0; i3 < 26; ++i3) {
      dp[i1][i2][i3] = kUnsolved;
    }
    
    return f(K, r, c);
  }

private:
  int N;
  const int mx[8] = {-2, -2,2,2,1,-1,1,-1};
  const int my[8] = {1, -1,1,-1,-2,-2,2,2};
  const int kUnsolved = -1;
  
  double f(int K, int r, int c) {
    if (!inside(r, c)) return 0;
    
    if (dp[K][r][c] != kUnsolved) return dp[K][r][c];
    
    if (K == 0) return dp[K][r][c]=1;
    
    double ans = 0;
    for (int i = 0; i < 8; ++i) {
      int x = r+mx[i], y = c+my[i];
      ans += f(K-1, x, y);
    }
    
    return dp[K][r][c]=ans/8;
  }
  
  bool inside(int r, int c) {
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
