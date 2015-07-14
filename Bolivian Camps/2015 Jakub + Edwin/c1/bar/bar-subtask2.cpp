#include <bits/stdc++.h>
using namespace std;

int main() {
  int values[256] = {0};
  values[(int)'p'] = 1;
  values[(int)'j'] = -1;
  
  int n;
  cin >> n;
  
  // Process only subtask 2
  if (n > 10000) {
    return 0;
  }
  
  string s;
  cin >> s;
  
  vector<int> fl(n);
  fl[0] = values[(int)s[0]];
  for(int i = 1; i < n; i++) {
    fl[i] = fl[i-1] + values[(int)s[i]];
  }
  
  vector<int> fr(n);
  fr[n - 1] = values[(int)s[n - 1]];
  for(int i = n - 2; i >= 0; i--) {
    fr[i] = fr[i+1] + values[(int)s[i]];
  }
  
  int ans = 0, cur = 0;
  vector<vector<int>> fl_mins(2, vector<int>(n, 0)), fr_mins(2, vector<int>(n, 0));
  
  // Base cases
  for(int i = 0; i < n; i++) {
    fl_mins[cur][i] = fl[i];
    fr_mins[cur][i] = fr[i];
    
    if (s[i] == 'p') {
      ans = 1;
    }
  }
  cur = 1 - cur;

  // General cases
  for(int len = 2; len <= n; len++) {
    for(int i = 0; i + len <= n; i++) {
      const int j = i + len - 1;
      
      fl_mins[cur][i] = min(fl_mins[1 - cur][i], fl[j]);
      fr_mins[cur][i] = min(fr_mins[1 - cur][i], fr[j]);
      
      int left = fl_mins[cur][i] - (i > 0 ? fl[i - 1] : 0);
      int right = fr_mins[cur][i] - (j < n - 1 ? fr[j + 1] : 0);
      
      if (left >= 0 && right >= 0 && j - i + 1 > ans) {
        ans = j - i + 1;
      }
    }
    cur = 1 - cur;
  }
  
  cout << ans << '\n';
  
  return 0;
}