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
    const int kMaxCoord = 10000;
    vector<vector<bool>> alive(kMaxCoord + 1,
                               vector<bool>(kMaxCoord + 1, false));

    vector<ii> glist(n);
    for (int i = 0; i < n; ++i) {
      int &x = glist[i].first, &y = glist[i].second;
      cin >> x >> y;
      alive[x][y] = true;
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
      int x, y, r;
      cin >> x >> y >> r;
      const int r2 = r * r;

      for (int a = -r; a <= r; ++a) {
        const int x2 = (x + a);
        if (x2 < 0 || x2 > kMaxCoord) continue;

        for (int b = -r; b <= r; ++b) {
          const int y2 = (y + b);
          if (y2 < 0 || y2 > kMaxCoord) continue;

          if (a * a + b * b > r2) continue;

          alive[x2][y2] = false;
        }
      }
    }

    int ans = n;
    for (auto &&p : glist) {
      if (!alive[p.first][p.second]) {
        ans -= 1;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
