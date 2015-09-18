#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using vi = vector<int>;
using ii = pair<int, int>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, x;
  while (cin >> n >> x) {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (x % i == 0 && (x / i) <= n) {
        ans += 1;
      }
    }
    cout << ans << endl;
  }
  
  return 0;
}
