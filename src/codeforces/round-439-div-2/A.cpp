// http://codeforces.com/problemset/problem/869/A

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
    vi a(n), b(n);
    set<int> seen;
    
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      seen.insert(a[i]);
    }    
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
      seen.insert(b[i]);
    }
    
    int ret = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int val = a[i] ^ b[j];
        if (seen.count(val) > 0) {
          ret += 1;
        }
      }
    }
    
    cout << (ret % 2 == 0 ? "Karen" : "Koyomi") << endl;
  }
  
  return 0;
}
