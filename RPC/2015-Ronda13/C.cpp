#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using vi = vector<int>;
using ii = pair<int, int>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  while (cin >> n >> k) {
    const int kMaxTime = 103000;
    vector<int> use(kMaxTime, 0);

    for (int i = 0; i < n; ++i) {
      int t;
      cin >> t;
      use[t] += 1;
      use[t + 1000] -= 1;
    }

    int cur = 0, ans = 0;
    for (int i = 0; i < kMaxTime; ++i) {
      cur += use[i];
      ans = max(ans, cur);
    }

    if (ans % k != 0) {
      ans = ans / k + 1;
    } else {
      ans /= k;
    }

    cout << ans << endl;
  }

  return 0;
}
