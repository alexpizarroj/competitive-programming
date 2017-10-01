#include <bits/stdc++.h>
using namespace std;

void solve_small(int n, int m) {
  string s;
  cin >> s;
  
  vector<int> sum(n + 1);
  for(int i = 1; i <= n; i++) {
    sum[i] = sum[i-1] + (s[i-1] == 'T' ? 2 : 1);
  }
  
  for(int cur = 0; cur < m; cur++) {
    int x;
    cin >> x;
    
    int ox = -1, oy;
    for(int i = 1; i <= n; i++) {
      for(int j = i; j <= n; j++) {
        if (sum[j] - sum[i-1] == x) {
          ox = i, oy = j;
        }
      }
    }
    
    if (ox != -1) {
      cout << ox << " " << oy << '\n';
    } else {
      cout << "NIE\n";
    }
  }
}

void solve_large(int n, int m) {
  string s;
  cin >> s;
  
  vector<int> a(n);
  int oo = -1, tt = -1;
  for(int i = 0; i < n; i++) {
    a[i] = (s[i] == 'T' ? 2 : 1);
    if (a[i] == 1) {
      oo = i;
    } else {
      tt = i;
    }
  }
  
  vector<int> sum(n);
  for(int i = 0; i < n; i++) {
    sum[i] = (i > 0 ? sum[i-1] : 0) + a[i];
  }
  
  vector<int> f(n, -1);
  for(int i = n-2; i >= 0; i--) {
    if (s[i] == 'W') {
      continue;
    }
    
    if (s[i+1] == 'W') {
      f[i] = 0;
    } else {
      f[i] = (f[i+1] == -1 ? -1 : f[i+1] + 1);
    }
  }
  
  vector<pair<int, int>> ans(sum.back() + 1, make_pair(-1, -1));
  ans[1] = {oo, oo};
  ans[2] = {tt, tt};
  for(int i = 1; i < n; i++) {
    if (ans[sum[i]].first == -1) {
        ans[sum[i]] = make_pair(0, i);
    }
    
    if (a[i] == 2) {
      const int k = sum[i] - 1;
      if (a[0] == 1) {
        ans[k] = {1, i};
      } else if (oo != -1) {
        if (f[i] == -1) {
          int x = f[0], cnt = (n - i - 1);
          if (x < cnt) {
            ans[k] = {0 + x + 2, i + x + 1};
          }
        } else {
          int x = f[0], y = f[i];
          if (x < y) {
            ans[k] = {x + 2, i + x + 1};
          } else if (x == y) {
            ans[k] = {x + 1, i + x + 1};
          } else {
            ans[k] = {y + 1, i + y + 1};
          }
        }
      }
    }
  }
  
  for(int i = 0; i < m; i++) {
    int x;
    cin >> x;
    if (x <= sum.back() && ans[x].first != -1) {
      cout << (ans[x].first + 1) << " " << (ans[x].second + 1) << '\n';
    } else {
      cout << "NIE\n";
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  
  if (n <= 100 && m <= 300) {
    solve_small(n, m);
  } else {
    solve_large(n, m);
  }
  
  return 0;
}