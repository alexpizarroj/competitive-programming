// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3102

#include <iostream>
#include <vector>
using namespace std;

struct Plot {
  int area;
  long long cost;
  Plot() : area(0), cost(0) {}
  Plot(int area, long long cost) : area(area), cost(cost) {}
};

bool operator>(const Plot& lhs, const Plot& rhs) {
  if (lhs.area != rhs.area) return lhs.area > rhs.area;
  return lhs.cost < rhs.cost;
}

Plot Solve(const vector<vector<int>>& grid, int money) {
  const int n = grid.size(), m = grid[0].size();

  Plot ans;

  for (int k = 0; k < n; ++k) {
    vector<long long> col_sum(m, 0);

    for (int i = k; i < n; ++i) {
      long long run_cost = 0;
      int run_start = 0;

      for (int j = 0; j < m; ++j) {
        col_sum[j] += grid[i][j];

        run_cost += col_sum[j];
        while (run_start <= j && run_cost > money) {
          run_cost -= col_sum[run_start];
          run_start += 1;
        }

        if (run_start > j) continue;

        int run_area = (i - k + 1) * (j - run_start + 1);
        Plot candidate(run_area, run_cost);
        if (candidate > ans) ans = candidate;
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
    int n, m, money;
    cin >> n >> m >> money;

    auto grid = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> grid[i][j];
      }
    }

    auto ans = Solve(grid, money);
    cout << "Case #" << tc << ": ";
    cout << ans.area << " " << ans.cost << endl;
  }

  return 0;
}
