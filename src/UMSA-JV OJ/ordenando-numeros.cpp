#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int tc;
  cin >> tc;
  
  for (int t = 1; t <= tc; t++) {
    int n;
    cin >> n;
    
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
      cin >> vec[i];
    }
    sort(begin(vec), end(vec));
    
    for (int i = 0; i < n; i++) {
      cout << vec[i] << " ";
    }
    cout << '\n';
  }
  
  return 0;
}
