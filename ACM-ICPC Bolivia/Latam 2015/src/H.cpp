#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using vi = vector<int>;
using vii = vector<ii>;
const int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};

int count_hor_faces(const vector<vi>& m) {
  const int r = m.size(), c = m[0].size();
  
  int res = 0;
  
  for (int j = 0; j < c; ++j) {
    for (int i = 1; i < r; ++i) {
      int x = m[i - 1][j], y = m[i][j];
      if (x == y) continue;
      
      int a = (j + 1 < c ? m[i - 1][j + 1] : inf);
      int b = (j + 1 < c ? m[i][j + 1] : inf);
      
      if (x < y) {
        if (b > x && b > a && y > a) continue;
        res += 1;
      } else {
        if (a > y && a > b && x > b) continue;
        res += 1;
      }
    }
  }
  
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int r, c;
  while (cin >> r >> c) {
    vector<vi> m(r, vi(c));
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        cin >> m[i][j];
      }
    }
    
    auto inside = [&](int x, int y) {
      return (0 <= x && x < r) && (0 <= y && y < c);
    };
    
    int top_faces = 0;
    {
      vector<vi> mm = m;
      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
          if (mm[i][j] == -1) continue;
          
          const int hh = mm[i][j];
          queue<ii> q;
          q.push(ii(i, j));
          mm[i][j] = -1;
          
          while (!q.empty()) {
            ii cur = q.front();
            q.pop();
            
            for (int k = 0; k < 4; ++k) {
              int x = cur.first + dx[k], y = cur.second + dy[k];
              if (!inside(x, y) || mm[x][y] != hh) continue;
              mm[x][y] = -1;
              q.push(ii(x, y));
            }
          }
          
          top_faces += 1;
        }
      }
    } // end of faces counting
    
    vector<vi> mm(c, vi(r));
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        mm[j][i] = m[i][j];
      }
    }
    
    int ans = 5 + top_faces + count_hor_faces(m) + count_hor_faces(mm);
    cout << ans << '\n';
  }
  
  return 0;
}
