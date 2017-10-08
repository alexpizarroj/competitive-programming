#include <bits/stdc++.h>
using namespace std;

const int kInf = 1000000007;
const long long kLongInf = (long long)kInf * kInf;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using vi = vector<int>;
using vii = vector<ii>;

class Solution {
 public:
  int n, m;

  int maxAreaOfIsland(vector<vector<int>>& grid) {
    this->n = grid.size();
    this->m = grid[0].size();

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        ans = max(ans, dfs(i, j, grid));
      }
    }
    return ans;
  }

  int dfs(int x, int y, vector<vector<int>>& grid) {
    if (x < 0 || x >= n || y < 0 || y >= m) return 0;
    if (grid[x][y] == 0) return 0;
    
    int ans = 1;
    grid[x][y] = 0;
    ans += dfs(x+1, y, grid);
    ans += dfs(x-1, y, grid);
    ans += dfs(x, y+1, grid);
    ans += dfs(x, y-1, grid);
    return ans;
  }
};

void main_impl() {
  Solution s;

  vector<vector<int>> test1 = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                               {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                               {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
  cout << s.maxAreaOfIsland(test1) << endl;

  vector<vector<int>> test2 = {{0, 0, 0, 0, 0, 0, 0, 0}};
  cout << s.maxAreaOfIsland(test2) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifndef ONLINE_JUDGE
  using get_time = chrono::steady_clock;
  using ms = chrono::milliseconds;
  auto startingTime = get_time::now();
#endif
  main_impl();
#ifndef ONLINE_JUDGE
  auto endingTime = get_time::now();
  auto diff = endingTime - startingTime;
  auto elapsedTime = chrono::duration_cast<ms>(diff).count();
  cerr << "Elapsed time: " << elapsedTime << " [ms]" << endl;
#endif
  return 0;
}
