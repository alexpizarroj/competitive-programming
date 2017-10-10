#include <iostream>
#include <vector>
using namespace std;

int FlipBit(int mask, int bitpos) {
  int bitvalue = (mask >> bitpos) & 1;
  if (bitvalue == 0) return mask | (1 << bitpos);
  return mask - (1 << bitpos);
}

int main() {
  int n;

  while (cin >> n) {
    const int kNumCorners = 1 << n;
    vector<int> values(kNumCorners);
    for (int i = 0; i < kNumCorners; ++i) {
      cin >> values[i];
    }

    vector<int> power(kNumCorners);
    for (int corner = 0; corner < kNumCorners; ++corner) {
      power[corner] = 0;
      for (int j = 0; j < n; ++j) {
        int neighbor = FlipBit(corner, j);
        power[corner] += values[neighbor];
      }
    }

    int ans = 0;
    for (int corner = 0; corner < kNumCorners; ++corner) {
      for (int j = 0; j < n; ++j) {
        int neighbor = FlipBit(corner, j);
        int cand = power[corner] + power[neighbor];
        if (cand > ans) ans = cand;
      }
    }

    cout << ans << endl;
  }
  return 0;
}
