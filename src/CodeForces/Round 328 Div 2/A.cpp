#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using vi = vector<int>;
using ii = pair<int, int>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<string> maze(8);
  while (cin >> maze[0]) {
    for (int i = 1; i < 8; ++i) {
      cin >> maze[i];
    }

    int turns_to_win[2] = {1000, 1000};
    for (int col = 0; col < 8; ++col) {
      // Player 1
      for (int row = 0; row < 8; ++row) {
        if (maze[row][col] == 'W') {
          turns_to_win[0] = min(turns_to_win[0], row);
          break;
        }

        if (maze[row][col] != '.') break;
      }
      // Player 2
      for (int row = 7; row >= 0; --row) {
        if (maze[row][col] == 'B') {
          turns_to_win[1] = min(turns_to_win[1], 7 - row);
          break;
        }

        if (maze[row][col] != '.') break;
      }
    }

    bool a_wins = (turns_to_win[0] <= turns_to_win[1]);
    cout << (a_wins ? 'A' : 'B') << '\n';
  }

  return 0;
}
