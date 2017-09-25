#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using vi = vector<int>;
using ii = pair<int, int>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  while (cin >> n) {
    int minx = inf, maxx = -inf, miny = inf, maxy = -inf;
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      minx = min(minx, x);
      miny = min(miny, y);
      maxx = max(maxx, x);
      maxy = max(maxy, y);
    }
    
    bool good = (minx < maxx && miny < maxy);
    if (good) {
      int area = (maxx - minx) * (maxy - miny);
      cout << area << endl;
    } else {
      cout << -1 << endl;
    }
  }
  
  return 0;
}
