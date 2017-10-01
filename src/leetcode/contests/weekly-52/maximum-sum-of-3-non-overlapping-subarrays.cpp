// https://leetcode.com/articles/maximum-sum-of-3-non-overlapping-intervals/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int K) {
    const int m = nums.size(), n = m-K+1;
    
    vector<int> sums(n, 0);
    
    for (int i = 0; i < K; ++i)
      sums[0] += nums[i];
    for (int i = 1; i < n; ++i)
      sums[i] = sums[i-1] + nums[K+i-1] - nums[i-1];
    
    vector<int> pre_idx(n);
    
    pre_idx[n-1] = n-1;
    for (int i = n-2; i >= 0; --i) {
      pre_idx[i] = pre_idx[i+1];
      if (sums[i] > sums[pre_idx[i]])
        pre_idx[i] = i;
    }
    
    int best = 0, best_i=-1, best_j=-1, best_k=-1;
    
    for (int i = 0; i < n-2*K; ++i) {
      for (int j = i+K; j < n-K; ++j) {
        int k = pre_idx[j+K];
        
        int cand = sums[i] + sums[j] + sums[k];
        if (cand > best) {
          best = cand;
          best_i = i, best_j = j, best_k = k;
        }
      }
    }
    
    return {best_i, best_j, best_k};
  }
};

void test1() {
  vector<int> v = {1,2,1,2,6,7,5,1};
  
  Solution s;
  auto ans = s.maxSumOfThreeSubarrays(v, 2);
  
  for (int x : ans) {
    cout << x << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  test1();
  
  return 0;
}
