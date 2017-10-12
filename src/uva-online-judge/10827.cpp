// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1768

#include <iostream>
#include <vector>
using namespace std;

int FindMaxSum(const vector<vector<int>>& grid, int max_side_len) {
  const int n = grid.size();
  int ans = grid[0][0];

  for (int k = 0; k < n; ++k) {
    vector<int> col_sum(n, 0);

    for (int i = k; i < k + max_side_len && i < n; ++i) {
      for (int j = 0; j < n; ++j) col_sum[j] += grid[i][j];

      for (int start_pos = 0; start_pos + max_side_len <= n; ++start_pos) {
        int run_value = 0;

        for (int j = start_pos; j < start_pos + max_side_len; ++j) {
          run_value += col_sum[j];
          if (run_value < 0) run_value = 0;
          if (run_value > ans) ans = run_value;
        }
      }
    }
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  for (int tc = 1; tc <= T; ++tc) {
    int n;
    cin >> n;

    auto grid = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> grid[i][j];
      }
    }

    auto extended_grid = vector<vector<int>>(2 * n, vector<int>(2 * n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        extended_grid[i][j] = grid[i][j];
        extended_grid[i + n][j] = grid[i][j];
        extended_grid[i][j + n] = grid[i][j];
        extended_grid[i + n][j + n] = grid[i][j];
      }
    }

    cout << FindMaxSum(extended_grid, n) << '\n';
  }

  return 0;
}
