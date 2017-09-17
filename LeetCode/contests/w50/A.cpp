#include <iostream>
using namespace std;

class Solution {
public:
  bool validPalindrome(string s) {
    const int n = s.size();
    if (n <= 2) return true;
    
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
      if (s[i] != s[j]) {
        return (isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1));
      }
    }
    
    return true;
  }
private:
  bool isPalindrome(const string& s, int a, int b) {
    for (int i = a, j = b; i < j; ++i, --j)
      if (s[i] != s[j])
        return false;
    return true;
  }
};

int main() {
  Solution s;
  cout << s.validPalindrome("23") << endl;
  cout << s.validPalindrome("232") << endl;
  cout << s.validPalindrome("213") << endl;
  cout << s.validPalindrome("3123") << endl;
  
  return 0;
}
