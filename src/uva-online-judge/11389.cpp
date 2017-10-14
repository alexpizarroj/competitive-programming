#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, d, r;
  while (cin >> n >> d >> r && n != 0) {
    vector<int> morning(n), afternoon(n);
    for (int i = 0; i < n; ++i) cin >> morning[i];
    for (int i = 0; i < n; ++i) cin >> afternoon[i];

    sort(begin(morning), end(morning));
    sort(begin(afternoon), end(afternoon), greater<int>());

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int work_time = morning[i] + afternoon[i];
      if (work_time > d) ans += (work_time - d) * r;
    };

    cout << ans << '\n';
  }

  return 0;
}
