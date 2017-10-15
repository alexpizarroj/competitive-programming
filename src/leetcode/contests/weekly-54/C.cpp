// https://leetcode.com/contest/leetcode-weekly-contest-54/problems/partition-to-k-equal-sum-subsets/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int n_, k_, target_sum_;
  vector<int> nums_;

  bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = accumulate(begin(nums), end(nums), 0);
    if (sum % k != 0) return false;

    n_ = nums.size();
    k_ = k;
    target_sum_ = sum / k;
    nums_ = nums;

    return rec((1 << n_) - 1, 0, 0, 0);
  }

  bool rec(int rem_nums_mask, int lo, int current_sum, int num_sets_built) {
    if (num_sets_built >= k_) return (rem_nums_mask == 0);

    if (current_sum == target_sum_)
      return rec(rem_nums_mask, 0, 0, num_sets_built + 1);

    if (k_ - num_sets_built > __builtin_popcount(rem_nums_mask)) return false;

    for (int i = lo; i < n_; ++i) {
      bool on = (rem_nums_mask >> i) & 1;
      if (!on) continue;

      const int x = nums_[i];
      if (current_sum + x > target_sum_) continue;

      int new_mask = rem_nums_mask - (1 << i);
      if (rec(new_mask, i + 1, current_sum + x, num_sets_built)) return true;
    }

    return false;
  }
};

void main_impl() {
  vector<int> test1{4, 3, 2, 3, 5, 2, 1};
  vector<int> test2{1, 2, 3};
  vector<int> test3{5, 2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3};
  vector<int> test4{4, 5, 3, 2, 5, 5, 5, 1, 5, 5, 5, 5, 3, 5, 5, 2};
  vector<int> test5{129,  17,  74,   57,  1421, 99,  92,  285,
                    1276, 218, 1588, 215, 369,  117, 153, 22};

  Solution s;
  cout << s.canPartitionKSubsets(test1, 4) << endl;
  cout << s.canPartitionKSubsets(test2, 2) << endl;
  cout << s.canPartitionKSubsets(test2, 3) << endl;
  cout << s.canPartitionKSubsets(test3, 15) << endl;
  cout << s.canPartitionKSubsets(test4, 13) << endl;
  cout << s.canPartitionKSubsets(test5, 3) << endl;
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
