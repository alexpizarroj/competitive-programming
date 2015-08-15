#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  const long long kMax = 1000000000000000000LL;
  long long ub[100] = {0, 1, 2, 4};
  int last = 3;
  while (ub[last] < kMax) {
    ub[last + 1] = ub[last] + ub[last-1] + 1;
    ++last;
  }
  
  int tc;
  cin >> tc;
  
  for (int i = 0; i < tc; ++i) {
    long long N;
    cin >> N;
    
    for (int j = 0; j <= last; ++j) {
      if (ub[j] >= N) {
        cout << j << '\n';
        break;
      }
    }
  }
  
  return 0;
}
