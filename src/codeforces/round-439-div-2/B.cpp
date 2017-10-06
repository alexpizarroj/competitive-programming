// http://codeforces.com/problemset/problem/869/B

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
  
  long long a, b;
  while (cin >> a >> b) {
    int ans = 1;
    for(long long i = a + 1; i <= b; ++i) {
      ans = (ans * (i % 10)) % 10;
      if (ans == 0) break;
    }
    cout << ans << endl;
  }
  
  return 0;
}
