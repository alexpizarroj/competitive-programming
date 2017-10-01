#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int tc;
  cin >> tc;
  
  for (int caso = 1; caso <= tc; ++caso) {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    
    vector<vector<int>> doc(n, vector<int>(m, -1));
    for (int i = 0; i < n; ++i) {
      string line;
      cin >> line;
      for (int j = 0; j < m; ++j) {
        if (line[j] == 'x') {
          doc[i][j] = 0;
        }
      }
    }
    
    int sx1 = inf, sx2 = -inf;
    int sy1 = inf, sy2 = -inf;
    int fx = -1, fy = -1;
    vector<string> sam(a);
    for (int i = 0; i < a; ++i) {
      cin >> sam[i];
      for (int j = 0; j < b; ++j) {
        if (sam[i][j] == 'x') {
          // Update seal rectangle
          sx1 = min(sx1, i);
          sx2 = max(sx2, i);
          sy1 = min(sy1, j);
          sy2 = max(sy2, j);
          // First droplet seen
          if (fx == -1) {
            fx = i, fy = j;
          }
        }
      }
    }
    
    auto inside = [&](int xx, int yy) {
      return (0 <= xx && xx < n && 0 <= yy && yy < m);
    };
    
    auto try_color = [&](int color, int srcx, int srcy) -> bool {
      int x1 = srcx - (fx - sx1), x2 = x1 + (sx2 - sx1);
      int y1 = srcy - (fy - sy1), y2 = y1 + (sy2 - sy1);
      if (!inside(x1, y1) || !inside(x2, y2)) {
        //cerr << "Failed with rectangle (" << x1 << " " << y1 << "), (" << x2
        //     << " " << y2 << ")\n";
        return false;
      }

      //cerr << "Filling rectangle (" << x1 << " " << y1 << "), (" << x2 << " "
      //     << y2 << ")\n";

      for (int i = x1; i <= x2; ++i) {
        for (int j = y1; j <= y2; ++j) {
          int sami = i - x1 + sx1, samj = j - y1 + sy1;
          if (sam[sami][samj] != '.') {
            if (doc[i][j] != 0) {
              return false;
            } else {
              doc[i][j] = color;
            }
          }
        }
      }
      
      return true;
    };
    
    bool ok = true;
    int next_color = 1;
    for (int i = 0; ok && i < n; ++i) {
      for (int j = 0; ok && j < m; ++j) {
        if (doc[i][j] == 0) {
          if (!try_color(next_color++, i, j)) {
            ok = false;
          }
        }
      }
    }
    
    cout << (ok ? "TAK\n" : "NIE\n");
    
    /*
    cerr << sx1 << " " << sx2 << endl;
    cerr << sy1 << " " << sy2 << endl;
    cerr << fx << " " << fy << endl;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cerr << setw(3) << doc[i][j];
      }
      cerr << '\n';
    }
    cerr << "end of test case\n\n";
    */
  }
  
  return 0;
}
