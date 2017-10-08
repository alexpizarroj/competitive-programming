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
  int n, m, nextId;

  int numDistinctIslands(vector<vector<int>>& grid) {
    this->n = grid.size();
    this->m = grid[0].size();
    this->nextId = 2;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] != 1) continue;
        dfs(i, j, grid);
        nextId += 1;
      }
    }

    vector<int> left(nextId, 1000000007);
    vector<int> top(nextId, 1000000007);
    vector<int> right(nextId, -1);
    vector<int> bot(nextId, -1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 0) continue;
        int val = grid[i][j];

        left[val] = min(j, left[val]);
        right[val] = max(j, right[val]);
        top[val] = min(i, top[val]);
        bot[val] = max(i, bot[val]);
      }
    }

    set<string> seen;
    for (int cc = 2; cc < nextId; ++cc) {
      int w = right[cc] - left[cc] + 1;
      int h = bot[cc] - top[cc] + 1;
      string val(h * (w+1), '*');

      int pos = 0;
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          int x = top[cc] + i, y = left[cc] + j;
          val[pos] = (grid[x][y] == cc ? '1' : '0');
          pos += 1;
        }
        pos += 1;
      }

      seen.insert(val);
    }

    return seen.size();
  }

  void dfs(int x, int y, vector<vector<int>>& grid) {
    if (x < 0 || x >= n || y < 0 || y >= m) return;
    if (grid[x][y] != 1) return;

    grid[x][y] = nextId;

    dfs(x + 1, y, grid);
    dfs(x - 1, y, grid);
    dfs(x, y + 1, grid);
    dfs(x, y - 1, grid);
  }
};

void main_impl() {
  Solution s;

  vector<vector<int>> test1 = {
      {1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 1, 1}};

  cout << s.numDistinctIslands(test1) << endl;

  vector<vector<int>> test2 = {
      {1, 1, 0, 1, 1}, {1, 0, 0, 0, 0}, {0, 0, 0, 0, 1}, {1, 1, 0, 1, 1}};
  cout << s.numDistinctIslands(test2) << endl;

  vector<vector<int>> test3 = {{0, 0, 1}, {0, 0, 1}, {1, 1, 0}};
  cout << s.numDistinctIslands(test3) << endl;
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
