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
    vector<int> speed(n);
    for (int i = 0; i < n; ++i) {
      cin >> speed[i];
    }

    vector<vi> masks(n + 1, vi());
    for (int i = 0; i < (1 << n); ++i) {
      int cnt = __builtin_popcount(i);
      masks[cnt].push_back(i);
    }

    vector<int> dp(1 << n, inf);
    // nppl stands for the number of people on the room

    dp[(1 << n) - 1] = 0;  // nppl = n

    for (int mask : masks[n - 1]) {  // nppl = n - 1
      for (int i = 0; i < n; ++i) {
        if (((mask >> i) & 1) == 0) {
          dp[mask] = min(dp[mask], speed[i]);
          break;
        }
      }
    }

    for (int nppl = n - 2; nppl >= 0; --nppl) {  // nppl <= n - 2
      for (int mask : masks[nppl]) {
        // 'i' and 'j' will travel together
        for (int i = 0; i < n; ++i) {
          if ((mask >> i) & 1) continue;
          for (int j = i + 1; j < n; ++j) {
            if ((mask >> j) & 1) continue;

            const int tmpmask = mask | (1 << i) | (1 << j);
            const int go_speed = max(speed[i], speed[j]);

            if (nppl < n - 2) {
              // 'k' will return with the cloak
              for (int k = 0; k < n; ++k) {
                if (((tmpmask >> k) & 1) == 0) continue;

                const int newmask = tmpmask & (~(1 << k));
                dp[mask] = min(dp[mask], go_speed + speed[k] + dp[newmask]);
              }
            } else {
              dp[mask] = min(dp[mask], go_speed);
            }
          }
        }
      }
    }

    cout << dp[0] << endl;
  }

  return 0;
}
