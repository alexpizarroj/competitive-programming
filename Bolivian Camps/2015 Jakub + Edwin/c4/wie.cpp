#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;
  
  vector<string> board(n);
  vector<bool> row(n, true), col(n, true);
  for (int i = 0; i < n; i++) {
    cin >> board[i];
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 'W') {
        row[i] = col[j] = false;
      }
    }
  }
  
  for (int i = 0; i < n; i++) {
    if (!row[i]) {
      continue;
    }
    for (int j = 0; j < n; j++) {
      if (!col[j]) {
        continue;
      }
      row[i] = col[j] = false;
      board[i][j] = 'W';
      break;
    }
  }
  
  for (const string& s : board) {
    cout << s << '\n';
  }
  
  return 0;
}
