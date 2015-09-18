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
    int x;
    cin >> x;
    
    multiset<int, greater<int>> st;
    for (int i = 1; i < n; ++i) {
      int y;
      cin >> y;
      st.insert(y);
    }
    
    int ans = 0;
    while (x <= *st.begin()) {
      x += 1;
      int y = *(st.begin()) - 1;
      st.erase(st.begin());
      st.insert(y);
      
      ans += 1;
    }
    cout << ans << '\n';
  }
  
  return 0;
}
