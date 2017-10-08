#include <bits/stdc++.h>
using namespace std;

const int kInf = 1000000007;
const long long kLongInf = (long long)kInf * kInf;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using vi = vector<int>;
using vii = vector<ii>;

class Solution {
public:
  bool hasAlternatingBits(int n) {
    if (n == 0) return false;

    int top = 31;
    while (true) {
      if ((n >> top) & 1) break;
      top -= 1;
    }
    cout << " " << top << endl;

    int last = n & 1;
    for (int i = 1; i <= top; ++i) {
      int cur = (n >> i) & 1;
      if (cur == last) return false;
      last = cur;
    }
    return true;
  }
};

void main_impl() {
  Solution s;
  cout << s.hasAlternatingBits(3) << endl;
  cout << s.hasAlternatingBits(5) << endl;
  cout << s.hasAlternatingBits(7) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifndef ONLINE_JUDGE
  using get_time = chrono::steady_clock;
  using ms = chrono::milliseconds;
  auto startingTime = get_time::now();
#endif
  main_impl();
#ifndef ONLINE_JUDGE
  auto endingTime = get_time::now();
  auto diff = endingTime - startingTime;
  auto elapsedTime = chrono::duration_cast<ms>(diff).count();
  cerr << "Elapsed time: " << elapsedTime << " [ms]" << endl;
#endif
  return 0;
}
