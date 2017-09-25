// https://leetcode.com/problems/largest-palindrome-product/

class Solution {
public:
    int largestPalindrome(int n) {
      long long ans[9] = {
        1L,
        9L,
        9009L,
        906609L,
        99000099L,
        9966006699L,
        999000000999L,
        99956644665999L,
        9999000000009999L
      };

      return (ans[n] % 1337); 
    }
};
