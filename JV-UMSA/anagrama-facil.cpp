#include <bits/stdc++.h>
using namespace std;

int main() {
  char buffer[1005];
  
  int tc;
  scanf("%d", &tc);
  
  for (int t = 1; t <= tc; t++) {
    int n;
    scanf("%d", &n);
    
    vector<string> vec(n);
    for (int i = 0; i < n; i++) {
      scanf("%s", buffer);
      vec[i] = string(buffer);
      sort(begin(vec[i]), end(vec[i]));
    }
    
    vector<string> svec = vec;
    sort(begin(svec), end(svec));
    svec.erase(unique(begin(svec), end(svec)), end(svec));
    
    vector<int> pos(n), freq(svec.size());
    for (int i = 0; i < n; i++) {
      auto it = lower_bound(begin(svec), end(svec), vec[i]);
      pos[i] = distance(begin(svec), it);
      freq[pos[i]] += 1;
    }
    
    for (int i = 0; i < n; i++) {
      int cnt = freq[pos[i]] - 1;
      if (i > 0) {
        printf(" ");
      }
      printf("%d", cnt);
    }
    puts("");
  }
  
  return 0;
}
