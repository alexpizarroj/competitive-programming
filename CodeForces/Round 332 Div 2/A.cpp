#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using vi = vector<int>;
using vii = vector<ii>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long d1, d2, d3;
  while (cin >> d1 >> d2 >> d3) {
    long long min_d1 = min(d1, d2 + d3);
    long long min_d2 = min(d2, d1 + d3);
    long long min_d3 = min(d3, d1 + d2);
    long long ans = min_d1 + min_d2 + min_d3;
    cout << ans << endl;
  }

  return 0;
}
