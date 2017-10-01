// https://leetcode.com/problems/candy/

class Solution {
public:
    int candy(vector<int>& ratings) {
      const int n = (int)ratings.size();
      
      vector<pair<int, int>> processingOrder;
      for (int i = 0; i < n; ++i) {
        processingOrder.push_back({ratings[i], i});
      }
      sort(begin(processingOrder), end(processingOrder));
      
      vector<int> candies(n, 1);
      for (auto&& kvp : processingOrder) {
        const int x = kvp.first, i = kvp.second;
        
        int newval = candies[i];
        if (i-1 >= 0 && ratings[i-1] < ratings[i]) {
          newval = max(newval, candies[i-1] + 1);
        }
        if (i+1 < n && ratings[i] > ratings[i+1]) {
          newval = max(newval, candies[i+1] + 1);
        }
        candies[i] = newval;
      }
      
      return accumulate(begin(candies), end(candies), 0);
    }
};
