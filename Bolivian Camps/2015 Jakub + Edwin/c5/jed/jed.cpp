#include <bits/stdc++.h>
using namespace std;

int main() {
  using ii = pair<int, int>;
  
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;
  
  vector<vector<int>> rail(3, vector<int>(n)), pos(3, vector<int>(n));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n; j++) {
      int val;
      cin >> val;
      val -= 1;
      
      rail[i][j] = val;
      pos[i][val] = j;
    }
  }
  
  map<ii, int> freq;
  for (int v = 0; v < n; v++) {
    int i = pos[0][v], j = pos[1][v], k = pos[2][v];
    int dj = (i - j + n) % n, dk = (i - k + n) % n;
    
    ii dpair(dj, dk);
    freq[dpair] += 1;
  }
  
  int ans = 0;
  for (auto&& p : freq) {
    ans = max(ans, p.second);
  }
  cout << ans << '\n';

  return 0;
}