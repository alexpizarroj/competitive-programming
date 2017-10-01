#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  vector<int> ord;
  map<int, int> freq;
  int x;
  while (cin >> x) {
    if (freq.count(x) == 0) {
      ord.push_back(x);
    }
    freq[x] += 1;
  }
  
  for (int i = 0; i < (int)ord.size(); i++) {
    cout << ord[i] << " " << freq[ord[i]] << '\n';
  }
  
  return 0;
}
