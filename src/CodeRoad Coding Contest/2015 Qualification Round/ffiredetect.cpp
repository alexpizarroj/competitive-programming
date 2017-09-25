#include <bits/stdc++.h>
using namespace std;

int getT(int i, int j, int z) {
  double sineOfAngle = sin((double)(i * j % 90));
  int T = (abs(int(1000 * sineOfAngle)) % z) + 1;
  return T;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int tc;
  cin >> tc;
  
  for (int cas = 1; cas <= tc; ++cas) {
    int n, m, f, z;
    cin >> n >> m >> f >> z;
    
    assert(1 <= n && n <= 10000);
    assert(1 <= m && m <= n);
    assert(1 <= f && f <= 1000000000);
    assert(2 <= z && z <= 11);
    
    int ans = 0;
    vector<vector<int> > mat(n, vector<int>(n, 0));
    
    // DP
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        mat[i][j] = getT(i, j, z);
        if (i > 0) mat[i][j] += mat[i-1][j];
        if (j > 0) mat[i][j] += mat[i][j-1];
        if (i > 0 && j > 0) mat[i][j] -= mat[i-1][j-1];
        
        if (i >= m - 1 && j >= m - 1) {
          const int x = i - m + 1, y = j - m + 1;
          int total = mat[i][j];
          if (x > 0) total -= mat[x-1][j];
          if (y > 0) total -= mat[i][y-1];
          if (x > 0 && y > 0) total += mat[x-1][y-1];
          if (total > f) {
            ans += 1;
          }
        }
      }
    }
    
    /*
    // BRUTEFORCE
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        mat[i][j] = getT(i, j, z);
      }
    }
    for (int i = 0; i + m <= n; ++i) {
      for (int j = 0; j + m <= n; ++j) {
        int total = 0;
        for (int a = 0; a < m; ++a) {
          for (int b = 0; b < m; ++b) {
            total += mat[i + a][j + b];
          }
        }
        if (total > f) {
          ans += 1;
        }
      }
    }*/
    
    cout << ans << endl;
  }
  
  return 0;
}
