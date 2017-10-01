#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  while (cin >> n) {
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
      cin >> vec[i];
    }
    if (n % 2 == 1) {
      sort(begin(vec), end(vec));
      cout << vec[n / 2] << '\n';
    } else {
      cout << "-1\n";
    }
  }
  
  return 0;
}
