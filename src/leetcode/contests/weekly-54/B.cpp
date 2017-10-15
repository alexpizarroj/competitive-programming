// https://leetcode.com/problems/count-binary-substrings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int countBinarySubstrings(string s) {
    const int n = s.size();

    vector<int> runlen(n, 1);
    for (int i = n - 2; i >= 0; --i)
      if (s[i] == s[i + 1]) runlen[i] += runlen[i + 1];

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int j = i + runlen[i];
      if (j < n && runlen[i] <= runlen[j]) ans += 1;
    }

    return ans;
  }
};

void main_impl() {
  Solution s;
  cout << s.countBinarySubstrings("00110011") << endl;
  cout << s.countBinarySubstrings("10101") << endl;
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
