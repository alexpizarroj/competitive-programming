#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    int x;
    cin >> x;
    int res = (1 << x) - 1;
    cout << res << '\n';
  }
  
  return 0;
}
