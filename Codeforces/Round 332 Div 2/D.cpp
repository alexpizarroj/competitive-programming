#include <bits/stdc++.h>
using namespace std;

using uint64 = unsigned long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  uint64 x;
  while (cin >> x) {
    vector<pair<uint64, uint64>> result;

    for (uint64 n = 1; n <= 1500000; ++n) {
      uint64 top = (6*x + n*n*n - n);
      uint64 bot = (3*n*n + 3*n);
      if (top % bot == 0) {
        uint64 m = top / bot;
        if (m < n) continue;
        
        result.emplace_back(m, n);
        if (n != m) result.emplace_back(n, m);
      }
    }

    sort(begin(result), end(result));

    cout << result.size() << '\n';
    for (auto&& p : result) {
      cout << p.first << " " << p.second << '\n';
    }
  }

  return 0;
}
