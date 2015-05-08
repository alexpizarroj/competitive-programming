#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int besthub(int R, int L, int X[], long long B) {
  vector<long long> sum(R + 1);
  sum[0] = 0;
  for (int i = 1; i <= R; i++) sum[i] = sum[i - 1] + X[i - 1];

  int lo = 1, hi = R;
  while (lo < hi) {
    int tam = (lo + hi + 1) / 2;
    bool possible = false;
    for (int s = 0, t = tam - 1; t < R; s++, t++) {
      int p = (s + t) / 2;
      long long cost = 0;
      cost += sum[s] - sum[p] + (p - s) * X[p];
      cost += sum[t + 1] - sum[p + 1] - (t - p) * X[p];
      if (cost <= B) {
        possible = true;
        break;
      }
    }
    if (possible)
      lo = tam;
    else
      hi = tam - 1;
  }
  return lo;
}
