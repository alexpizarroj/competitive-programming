#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> vh(10005, 0);
  
  int l, h ,r, max_r = 0;
  while (cin >> l >> h >> r) {
    for(int i = l; i < r; i++) {
      if (h > vh[i]) {
        vh[i] = h;
      }
    }
    max_r = max(r, max_r);
  }

  int cur_h = 0;
  bool first_couple = true;
  
  for(int i = 0; i <= max_r; i++) {
    if(vh[i] != cur_h) {
      cur_h = vh[i];
      cout << (first_couple ? "" : " ") << i << " " << vh[i];
      first_couple = false;
    }
  }
  cout << '\n';

  return 0;
}
