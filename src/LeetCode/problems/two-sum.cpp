// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> tmp(begin(nums), end(nums));
        sort(begin(tmp), end(tmp));
        
        int i = 0, j = (int)tmp.size() - 1;
        while (tmp[i] + tmp[j] != target) {
            if (tmp[i] + tmp[j] < target) {
                i += 1;
            } else {
                j -= 1;
            }
        }
        
        vector<int> result(2, 0);
        
        for(int c = 0; c < (int)nums.size(); c++) {
            if (nums[c] == tmp[i]) {
                result[0] = c;
                break;
            }
        }
        
        for(int c = 0; c < (int)nums.size(); c++) {
            if (c == result[0]) {
                continue;
            }
            if (nums[c] == tmp[j]) {
                result[1] = c;
                break;
            }
        }
        
        if (result[0] > result[1]) {
            swap(result[0], result[1]);
        }
        result[0] += 1, result[1] += 1;
        
        return result;
    }
};
