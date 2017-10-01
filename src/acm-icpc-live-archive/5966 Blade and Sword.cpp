#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

struct State
{
  int x, y, from_portal;

  State() : x(-1), y(-1), from_portal(0) {}

  State(int _x, int _y, int _a) : x(_x), y(_y), from_portal(_a) {}

  bool operator==(const State &rhs) const
  {
    return (x == rhs.x && y == rhs.y &&
      from_portal == rhs.from_portal);
  }
};

class Solver
{
private:
  vector<ii> kMoves, portals;
  vector<string> maze;
  int m, n, dist[205][205][2];
  bool forth_done;

public:
  int& GetDistRef(const State &s)
  {
    return dist[s.x][s.y][s.from_portal];
  }

  vector<State> GetForwardList(const State &s)
  {
    vector<State> res;

    if (maze[s.x][s.y] != '*' || s.from_portal)
    {
      for(ii my_move : kMoves)
      {
        int xx = s.x + my_move.first, yy = s.y + my_move.second;
        if (xx < 0 || xx >= m || yy < 0 || yy >= n)
          continue;
        if (maze[xx][yy] == '#')
          continue;
        res.push_back(State(xx, yy, 0));
      }
    }

    if (maze[s.x][s.y] == '*')
    {
      if (!forth_done)
      {
        for(ii p : portals)
          if (p.first != s.x || p.second != s.y)
            res.push_back(State(p.first, p.second, 1));
        portals.clear();
        portals.push_back(ii(s.x, s.y));
        forth_done = true;
      }
      else
      {
        ii next = portals.back();
        res.push_back(State(next.first, next.second, 1));
      }
    }

    return move(res);
  }

  void Solve()
  {
    cin >> m >> n;
    maze.resize(m);
    for(int i = 0; i < m; i++)
      cin >> maze[i];
    kMoves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    State begin_state, end_state;
    for(int i = 0; i < m; i++)
    {
      for(int j = 0; j < n; j++)
      {
        if (maze[i][j] == 'P')
        {
          begin_state.x = i;
          begin_state.y = j;
        }
        else if (maze[i][j] == 'D')
        {
          end_state.x = i;
          end_state.y = j;
        }
        else if (maze[i][j] == '*')
        {
          portals.push_back(ii(i, j));
        }
      }
    }

    queue<State> q;
    memset(dist, -1, sizeof dist);
    q.push(begin_state);
    GetDistRef(begin_state) = 0;
    forth_done = false;
    while (!q.empty())
    {
      State s = q.front();
      q.pop();
      if (s == end_state)
        break;

      vector<State> adj = GetForwardList(s);
      for(State &t : adj)
      {
        if (GetDistRef(t) != -1)
          continue;
        GetDistRef(t) = GetDistRef(s) + 1;
        q.push(t);
      }
    }

    int ans = GetDistRef(end_state);
    cout << (ans == -1 ? "impossible" : to_string(ans)) << '\n';
  }
};

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for(int i = 1; i <= tc; i++)
  {
    cout << "Case " << i << ": ";
    Solver s;
    s.Solve();
  }
  return 0;
}
