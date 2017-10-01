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
  
  int n;
  while (cin >> n) {
    string s;
    cin >> s;
    
    set<char> cnt;
    int ans = 0;
    
    for (int i = 0; i < n; ++i) {
      if (isupper(s[i])) {
        cnt.clear();
      } else {
        cnt.insert(s[i]);
        ans = max(ans, (int)cnt.size());
      }
    }
    
    cout << ans << endl;
  }
  
  return 0;
}
