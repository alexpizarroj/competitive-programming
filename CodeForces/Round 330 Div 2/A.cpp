#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using vi = vector<int>;
using ii = pair<int, int>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, m;
  while (cin >> n >> m) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int x, y;
        cin >> x >> y;
        if (x || y) ans += 1;
      }
    }
    cout << ans << endl;
  }
  
  return 0;
}
