// https://leetcode.com/problems/partition-equal-subset-sum/description/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0);
        if (sum & 1 == 1) return false;
        
        vector<bool> possible(sum + 1, false);
        possible[0] = true;
        
        for (int num : nums)
            for (int value = sum; value >= num; --value)
                if (possible[value - num]) possible[value] = true;
        
        return possible[sum / 2];
    }
};
