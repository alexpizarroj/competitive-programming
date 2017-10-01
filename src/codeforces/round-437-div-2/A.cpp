// http://codeforces.com/contest/867/problem/A

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
  string s;
  while (cin >> n >> s) {
    char p = s[0];
    int stof = 0, ftos = 0;
    for (int i = 1; i < n; ++i) {
      if (p != s[i]) {
        if (p == 'S') stof += 1;
        if (p == 'F') ftos += 1;
      }
      p = s[i];
    }
    
    cout << (stof > ftos ? "YES" : "NO") << endl;
  }
  
  return 0;
}
