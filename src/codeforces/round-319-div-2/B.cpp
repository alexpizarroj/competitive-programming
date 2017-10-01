#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using vi = vector<int>;
using ii = pair<int, int>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, m;
  while (cin >> n >> m) {
    vector<int> modpre(2 * m);
    for (int i = 0; i < 2 * m; ++i) {
      modpre[i] = i % m;
    }
    
    vector<vector<bool>> reached(2, vector<bool>(m, false));
    int cur = 0, last = 1;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      if (reached[last][0]) continue;
      
      // Clean
      for (int j = 0; j < m; ++j) {
        reached[cur][j] = false;
      }
      // Set
      x %= m;
      reached[cur][x] = true;
      for (int j = 0; j < m; ++j) {
        if (reached[last][j]) {
          reached[cur][j] = true;
          reached[cur][modpre[j + x]] = true;
        }
      }
      
      swap(cur, last);
    }
    
    /*
    for (int i = 0; i < m; ++i) { 
      cout << (reached[last][0] ? "1" : "0");
    }
    cout << endl;
    */
    
    cout << (reached[last][0] ? "YES" : "NO") << '\n';
  }
  
  return 0;
}
