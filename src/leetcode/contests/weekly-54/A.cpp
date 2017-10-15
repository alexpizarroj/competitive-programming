// https://leetcode.com/problems/degree-of-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findShortestSubArray(vector<int>& nums) {
    map<int, int> freq, first_seen, last_seen;
    int top_freq = 0;

    for (int i = 0; i < (int)nums.size(); ++i) {
      int x = nums[i];
      freq[x] += 1;
      top_freq = max(top_freq, freq[x]);

      if (first_seen.count(x) == 0) first_seen[x] = i;
      last_seen[x] = i;
    }

    int ans = 1000000007;
    for (int x : nums) {
      if (freq[x] != top_freq) continue;
      int cand = last_seen[x] - first_seen[x] + 1;
      if (cand < ans) ans = cand;
    }

    return ans;
  }
};

void main_impl() {
  vector<int> test1{1, 2, 2, 3, 1, 4, 2};
  cout << Solution().findShortestSubArray(test1) << endl;
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
