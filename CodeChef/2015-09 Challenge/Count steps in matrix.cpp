#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using vi = vector<int>;
using ii = pair<int, int>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int tc;
  cin >> tc;
  
  for (int cas = 1; cas <= tc; ++cas) {
    int n;
    cin >> n;
    
    vector<ii> pos(n * n + 1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int value;
        cin >> value;
        pos[value] = ii(i, j);
      }
    }
    
    int cost = 0;
    for (int i = 2; i <= n * n; ++i) {
      cost += abs(pos[i - 1].first - pos[i].first);
      cost += abs(pos[i - 1].second - pos[i].second);
    }
    
    cout << cost << '\n';
  }
  
  return 0;
}
