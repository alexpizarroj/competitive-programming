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
    int n, m;
    cin >> n >> m;
    
    vector<int> vec(m);
    for (int i = 0; i < m; ++i) {
      cin >> vec[i];
    }
    sort(begin(vec), end(vec));
    
    int steps = 0, i = 0, sz = m;
    while (sz != 1) {
      int lchain = vec[i];
      if (lchain == 1 && sz != 2) {
        i += 1;
        sz -= 1;
      } else {
        vec[i] = lchain - 1;
      }
      
      const int j = i + sz - 1;
      vec[j-1] = vec[j] + vec[j-1] + 1;
      sz -= 1;
      
      steps += 1;
    }
    
    cout << steps << endl;
  }
  
  return 0;
}
