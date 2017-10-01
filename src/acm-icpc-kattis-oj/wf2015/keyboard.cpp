/*
** @author Alex Erick Pizarro Jimenez
*/
#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int to_int(int i, int j, int r, int c) {
  return (i * c) + j;
}

bool in_range(int i, int j, int r, int c) {
  return (0 <= i && i < r && 0 <= j && j < c);
}

int main() {
  const vector<ii> kMoves = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
  };
  
  int r, c; 
  cin >> r >> c;
  const int n = r * c; // Number of keys
  
  vector<string> kb;
  for(int i = 0; i < r; i++) {
    string row;
    cin >> row;
    kb.push_back(row);
  }
  
  string target;
  cin >> target;
  target += '*';
  const int m = target.size() + 1; // Number of possible current keys
  
  vector<vector<int>> adj(n, vector<int>());
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      for(int k = 0; k < (int)kMoves.size(); k++) {
        int rr = i, cc = j;
        while (in_range(rr, cc, r, c) && kb[rr][cc] == kb[i][j]) {
          rr += kMoves[k].first;
          cc += kMoves[k].second;
        }
        if (in_range(rr, cc, r, c)) {
          int id1 = to_int(i, j, r, c);
          int id2 = to_int(rr, cc, r, c);
          adj[id1].push_back(id2);
        }
      }
    }
  }
  
  const int n_states = n * m;
  vector<int> visited(n_states, -1);
  queue<int> q;
  
  int start = to_int(0, to_int(0, 0, r, c), m, n);
  visited[start] = 0;
  q.push(start);
  
  int ans = -1;
  while (!q.empty()) {
    const int ss = q.front();
    const int cell = ss % n;
    const int pos = ss / n;
    q.pop();
    
    if (pos == m - 1) {
      ans = visited[ss];
      break;
    }
    
    const int ii = cell / c, jj = cell % c;
    //printf("Processing ([%d, %d], %d), cost = %d\n", ii, jj, pos, visited[ss]);
    
    // Regular neighbors
    for(auto next_cell : adj[cell]) {
      const int next = to_int(pos, next_cell, m, n);
      if (visited[next] != -1) { continue; }
      
      //printf("\tNeighbor ([%d, %d], %d)\n", next_cell / c, next_cell % c, pos);
      q.push(next);
      visited[next] = visited[ss] + 1;
    }
    
    // We can 'select' this cell and continue
    if (target[pos] == kb[ii][jj]) {
      const int next = to_int(pos + 1, cell, m, n);
      if (visited[next] != -1) { continue; }
      
      //printf("\tNeighbor ([%d, %d], %d)\n", ii, jj, pos + 1);
      q.push(next);
      visited[next] = visited[ss] + 1;
    }
  }
  
  // Result
  cout << ans << endl;
  
  return 0;
}