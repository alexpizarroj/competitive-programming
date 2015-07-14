#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cout << ('z' - 'a' + 1) << endl;
  
  int tc;
  cin >> tc;
  
  for (int i = 0; i < tc; ++i) {
    int k;
    cin >> k;
    int ans = (1 << k) - 1;
    cout << ans << '\n';
  }
  
  return 0;
}
