#include <bits/stdc++.h>
using namespace std;

int to_base(int x, int b) {
  string res = "";
  do {
    char c = (x % b) + '0';
    res.push_back(c);
    x /= b;
  } while (x > 0);
  reverse(begin(res), end(res));
  
  istringstream iss(res);
  int intres;
  iss >> intres;
  
  return intres;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int tc;
  cin >> tc;
  
  for (int t = 1; t <= tc; t++) {
    int n, a;
    cin >> n >> a;
    
    for (int b = 2; b <= 9; b++) {
      if (to_base(n, b) == a) {
        cout << b << '\n';
        break;
      }
    }
  }
  
  return 0;
}
