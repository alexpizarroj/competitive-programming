#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
const int inf = 1000000007;
const long long inf64 = (long long)inf * inf;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  while (cin >> n >> k) {
    int splits = 0, chains = 0;

    for(int i = 0; i < k; i++) {
      //const int prev_splits = splits;
      //const int prev_chains = chains;

      int m;
      cin >> m;

      int last;
      cin >> last;

      bool initchain = (last == 1);
      if (!initchain) {
        chains += m;
        splits += m - 1;
        for(int j = 0; j < m - 1; j++) {
          int x;
          cin >> x;
        }
      } else {
        chains += 1;

        bool failed = false;
        for(int j = 0; j < m - 1; j++) {
          int x;
          cin >> x;

          failed = failed || (last + 1 != x);
          if (failed) {
            splits += 1;
            chains += 1;
          }

          last = x;
        }
      }

      //cout << (splits - prev_splits) << " " << (chains - prev_chains) << '\n';
    }

    int result = splits + chains - 1;
    cout << result << '\n';
  }

  return 0;
}
