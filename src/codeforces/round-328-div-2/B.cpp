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
    long long res = 0;
    if (n <= 3) {
      res = 1;
    } else {
      long long sides = 2;
      if (4 < n) sides += n - 4;
      res = sides * (n - 2);
    }
    cout << res << endl;
  }

  return 0;
}
