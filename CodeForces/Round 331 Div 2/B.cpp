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
    long long ans = 0;
    long long var = 0;
    for (int i = 0; i < n; ++i) {
      long long a;
      cin >> a;
      
      long long add = a - var;
      ans += abs(add);
      var += add;
    }
    
    cout << ans << endl;
  }
  
  return 0;
}
