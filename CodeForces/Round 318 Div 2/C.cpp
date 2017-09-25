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
    vi vec(n);
    for (int i = 0; i < n; ++i) {
      cin >> vec[i];
      while ((vec[i] & 1) == 0) vec[i] >>= 1;
      while (vec[i] % 3 == 0)  vec[i] /= 3;
    }
    
    bool ok = true;
    for (int i = 1; i < n; ++i) {
      if (vec[i-1] != vec[i]) {
        ok = false;
        break;
      }
    }
    cout << (ok ? "Yes\n" : "No\n");
  }
  
  return 0;
}
