#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using vi = vector<int>;
using vii = vector<ii>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  while (cin >> n) {
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      cnt[x] += 1;
    }
    
    auto it1 = cnt.begin();
    auto it2 = cnt.begin(); ++it2;
    
    bool good = (cnt.size() == 2 && it1->second == it2->second);
    cout << (good ? "YES" : "NO") << endl;
    if (good) {
      for (auto&& x : cnt) {
        cout << x.first << " ";
      }
      cout << endl;
    }
  }
  
  return 0;
}
