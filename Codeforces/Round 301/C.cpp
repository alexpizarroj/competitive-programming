#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

vector<ii> getNeighbors(ii pos, const vector<string> &maze) {
  static const vector<ii> kMoves = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
  };
  
  const int n = maze.size(), m = maze[0].size();
  vector<ii> result;
  for(auto mv : kMoves) {
    ii cand(pos.first + mv.first, pos.second + mv.second);
    if (0 <= cand.first && cand.first < n && 0 <= cand.second && cand.second < m) {
      if (maze[cand.first][cand.second] == '.') {
        result.push_back(cand);
      }
    }
  }
  
  return result;
}

bool bfs(ii bb, ii ee, vector<string> &maze) {
  const int n = maze.size(), m = maze[0].size();
  const ii kDefaultPrev(-1, -1);
  
  vector<vector<ii>> prev(n, vector<ii>(m, kDefaultPrev));
  vector<string> local_maze = maze;
  queue<ii> q;
  q.push(bb);
  
  while (!q.empty()) {
    ii cur = q.front();
    q.pop();
    
    if (cur == ee) {
      // Update the taken path
      while (prev[cur.first][cur.second] != kDefaultPrev) {
        maze[cur.first][cur.second] = 'X';
        cur = prev[cur.first][cur.second];
      }
      // Signal we found a path in a hopeless place <3
      return true;
    }
    
    for(auto next : getNeighbors(cur, local_maze)) {
      local_maze[next.first][next.second] = 'X';
      prev[next.first][next.second] = cur;
      q.push(next);
    }
  }
  
  return false;
}

bool solve(int n, int m) {
  vector<string> maze(n);
  for(int i = 0; i < n; i++) {
    cin >> maze[i];
  }
  
  ii bb, ee;
  cin >> bb.first >> bb.second;
  cin >> ee.first >> ee.second;
  bb.first -= 1, bb.second -= 1;
  ee.first -= 1, ee.second -= 1;
  
  // Can I reach the target cell?
  char target_status = maze[ee.first][ee.second];
  maze[ee.first][ee.second] = '.'; 
  if (bfs(bb, ee, maze) == false) {
    return false;
  }
  
  // Handle da special cases, yo
  if (target_status == '.' || bb == ee) {
    if ((int)getNeighbors(ee, maze).size() == 0) {
      return false;
    }
  }
  
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m;
  while (cin >> n >> m) {
    bool ans = solve(n, m);
    cout << (ans ? "YES" : "NO") << '\n';
  }

  return 0;
}