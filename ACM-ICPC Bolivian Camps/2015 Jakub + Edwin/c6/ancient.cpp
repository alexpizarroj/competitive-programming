#include <bits/stdc++.h>
using namespace std;

int main() {
  using ii = pair<int, int>;
  const vector<ii> kMoves = {{0,1}, {0,-1}, {1,0}, {-1,0}};
  const string kHoleMap = "0WAKJSD";
  
  int caso = 0;
  while (true) {
    caso += 1;
    
    int h, w;
    cin >> h >> w;
    if (h == 0) {
      break;
    }
    cin.ignore(1);
    
    vector<vector<bool>> pic(h+2, vector<bool>(w * 4 + 2, false));
    for (int i = 1; i <= h; i++) {
      for (int j = 0; j < w; j++) {
        char c;
        cin >> c;
        const int val = ('0' <= c && c <= '9' ? c - '0' : c -'a' + 10);
        
        for (int k = 0; k < 4; k++) {
          if ((val >> (3 - k)) & 1) {
            pic[i][1 + j * 4 + k] = true;
          }
        }
      }
      cin.ignore(1);
    }
    h = pic.size(), w = pic[0].size();
    
    auto inside = [&](int x, int y) -> bool {
      return (0 <= x && x < h) && (0 <= y && y < w);
    };
    
    int next_cc = 0;
    vector<vector<int>> cc(h, vector<int>(w, -1));
    function<void(int, int)> cc_dfs = [&](int x, int y) {
      cc[x][y] = next_cc;
      for (auto&& p : kMoves) {
        int xx = x + p.first , yy = y + p.second;
        if (inside(xx, yy) && cc[xx][yy] == -1 && pic[xx][yy]) {
          cc_dfs(xx, yy);
        }
      }
    };
    
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (cc[i][j] == -1 && pic[i][j] == true) {
          cc_dfs(i, j);
          next_cc += 1;
        }
      }
    }
    
    vector<int> cc_touch_cnt(next_cc, 0);
    vector<bool> touched(next_cc);
    function<void(int, int)> dfs = [&](int x, int y) {
      cc[x][y] = -2;
      for (auto&& p : kMoves) {
        int xx = x + p.first , yy = y + p.second;
        if (!inside(xx, yy)) {
          continue;
        }
        
        if (pic[xx][yy]) {
          int a = cc[xx][yy];
          if (!touched[a]) {
            touched[a] = true;
            cc_touch_cnt[a] += 1;
          }
          
        } else if (cc[xx][yy] == -1) {
          dfs(xx, yy);
        }
      }
    };
    
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (cc[i][j] == -1 && pic[i][j] == false) {
          touched.assign(next_cc, false);
          dfs(i, j);
        }
      }
    }
    
    string result(next_cc, ' ');
    for (int i = 0; i < next_cc; i++) {
      result[i] = kHoleMap[cc_touch_cnt[i]];
    }
    sort(begin(result), end(result));
    
    cout << "Case " << caso << ": " << result << '\n';
  }
  
  return 0;
}