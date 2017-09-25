#include <bits\stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  const int inf = 1000000007;
  const string kUnwalkable = "<>^v#";
  const string kTurrets = "<>^v";
  map<char, pair<int,int>> kTurretMoves =
  {
    {'<', {0,-1}}, {'>', {0,1}},
    {'^', {-1,0}}, {'v', {1,0}}
  };
  map<char, char> kNextRotation =
  {
    {'<', '^'}, {'^', '>'},
    {'>', 'v'}, {'v', '<'}
  };
  vector<pair<int, int>> kRegularMoves =
  {
    {1, 0}, {-1, 0}, {0,-1}, {0, 1}
  };

  int t;
  cin >> t;
  for(int tc = 1;  tc <= t; tc++)
  {
    int m, n;
    cin >> m >> n;

    vector<string> maze(m);
    for(int i = 0; i < m; i++)
      cin >> maze[i];

    pair<int, int> start, goal;
    for(int i = 0; i < m; i++)
    {
      for(int j = 0; j < n; j++)
      {
        if (maze[i][j] == 'S')
          start = {i, j};
        else if (maze[i][j] == 'G')
          goal = {i, j};
      }
    }

    vector< vector< vector<bool> > > valid_mark;
    valid_mark.assign(m, vector< vector<bool> >(n, vector<bool>(5, true)));
    for(int i = 0; i < m; i++)
    {
      for(int j = 0; j < n; j++)
      {
        if (kTurrets.find(maze[i][j]) == string::npos)
          continue;

        char face = kNextRotation[maze[i][j]];
        int time_mark = 1;
        do
        {
          const pair<int, int> var = kTurretMoves[face];
          int x = i + var.first, y = j + var.second;
          while (0 <= x && x < m && 0 <= y && y < n)
          {
            if (kUnwalkable.find(maze[x][y]) != string::npos)
              break;

            valid_mark[x][y][time_mark] = false;
            x += var.first;
            y += var.second;
          }

          time_mark += 1;
          face = kNextRotation[face];
        }
        while (time_mark <= 4);
      }
    }
    
    /*
    for(int i = 0; i < m; i++)
    {
      for(int j = 0; j < n; j++)
      {
        cout << "(" << i << ", " << j << ") =";
        for(int k = 0; k <= 4; k++)
          cout << " " << valid_mark[i][j][k];
        cout << endl;
      }
    }
    */
    
    vector< vector< vector<int> > > dist;
    dist.assign(m, vector< vector<int> >(n, vector<int>(5, inf)));
    dist[start.first][start.second][0] = 0;
    queue< pair<int, pair<int,int> > > q;
    q.push(make_pair(0, start));
    while (!q.empty())
    {
      const int mark = q.front().first;
      const pair<int,int> pos = q.front().second;
      q.pop();

      if (pos == goal)
        break;

      for(pair<int, int> var : kRegularMoves)
      {
        const int x = pos.first + var.first;
        const int y = pos.second + var.second;
        if (0 <= x && x < m && 0 <= y && y < n &&
          kUnwalkable.find(maze[x][y]) == string::npos)
        {
          const int next_mark = (mark == 4 ? 1 : mark + 1);
          if (dist[x][y][next_mark] == inf && valid_mark[x][y][next_mark])
          {
            dist[x][y][next_mark] = dist[pos.first][pos.second][mark] + 1;
            q.push(make_pair(next_mark, make_pair(x, y)));
          }
        }
      }
    }
    
    int ans = inf;
    for(int i = 0; i <= 4; i++)
      ans = min(ans, dist[goal.first][goal.second][i]);

    cout << "Case #" << tc << ": " 
      << (ans == inf ? "impossible" : to_string(ans)) << endl;
  }
  
  return 0;
}
