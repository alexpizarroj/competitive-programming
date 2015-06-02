#include <bits/stdc++.h>
using namespace std;

struct Cell {
  bool goes_beyond, has_friends;
};

int main() {
  const vector<pair<int, int>> kMoves = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
  };
  const string kMovesDir = "v>^<";

  int tc;
  cin >> tc;

  for(int tt = 1; tt <= tc; tt++) {
    int r, c;
    cin >> r >> c;

    vector<string> maze;
    for(int i = 0; i < r; i++) {
      string row;
      cin >> row;
      maze.push_back(row);
    }

    auto inside = [r, c](int i, int j) -> bool {
      return (0 <= i && i < r && 0 <= j && j < c);
    };

    vector<vector<Cell>> ci(r, vector<Cell>(c));
    for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
        Cell& c = ci[i][j];
        c.goes_beyond = false;
        c.has_friends = false;

        if (maze[i][j] == '.') {
          continue;
        }

        for(int k = 0; k < (int)kMoves.size(); k++) {
          int x = i, y = j;
          do {
            x += kMoves[k].first;
            y += kMoves[k].second;
          }
          while (inside(x, y) && maze[x][y] == '.');

          if (maze[i][j] == kMovesDir[k]) {
            c.goes_beyond = !inside(x, y);
          }
          if (inside(x, y)) {
            c.has_friends = true;
          }
        }
      }
    }

    int ans = 0;
    bool ok = true;
    for(int i = 0; ok && i < r; i++) {
      for(int j = 0; ok && j < c; j++) {
        //cout << "Cell(" << i << ", " << j << ") : ";
        //cout << ci[i][j].goes_beyond << " " << ci[i][j].has_friends << endl;

        if (!ci[i][j].goes_beyond) {
          continue;
        }

        if (ci[i][j].has_friends) {
          ans += 1;
        } else {
          ok = false;
        }
      }
    }

    string result = (ok ? to_string(ans) : "IMPOSSIBLE");
    cout << "Case #" << tt << ": " << result << '\n';
  }

  return 0;
}
