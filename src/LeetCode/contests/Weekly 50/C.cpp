#include <iostream>
#include <map>
#include <cstring>
#include <string>
using namespace std;

class Solution {
public:
  bool checkValidString(string s) {
    if (isValid(s)) return true;
    
    int sum = 0, jokers = 0;
    int leftmostJokersUsed = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
      if (s[i] == '(') sum += 1;
      if (s[i] == ')') sum -= 1;
      if (s[i] == '*') jokers += 1;
      
      if (sum < 0) {
        if (jokers > 0) {
          jokers -= 1;
          leftmostJokersUsed += 1;
          sum += 1;
        } else {
          return false;
        }
      }
    }
    
    if (sum == 0) return true;
    if (sum > jokers) return false;
    
    //cerr << "Fixing: " << s << endl;
    //cerr << "Stats: " << sum << " " << jokers << endl;
    
    const int n = s.size();
    if (sum > 0) {
      // Show Leftmost Jokers used
      for (int i = 0; i < n && leftmostJokersUsed > 0; ++i) {
        if (s[i] == '*') {
          s[i] = '(';
          leftmostJokersUsed -= 1;
        }
      }
      // Fix Sum Surplus
      for (int i = n - 1; i >= 0 && sum > 0; --i) {
        if (s[i] == '*') {
          s[i] = ')';
          sum -= 1;
        }
      }
    }
    
    return isValid(s);
  }

  bool isValid(const string& s, bool verbose = false) {
    int sum = 0;
    bool good = true;
    for (int i = 0; i < (int)s.size(); ++i) {
      if (s[i] == '(') sum += 1;
      if (s[i] == ')') sum -= 1;
      if (verbose) cerr << sum << " ";
      if (sum < 0) good = false;
    }
    if (verbose) cerr << endl;
    return (good && sum == 0);
  }
};

int main() {
  Solution s;
  cout << s.checkValidString("()") << endl;
  cout << s.checkValidString("(*)") << endl;
  cout << s.checkValidString("(*))") << endl;
  cout << s.checkValidString(")(") << endl;
  cout << s.checkValidString("((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(((((())*)))()))(()((*()*(*)))(*)()") << endl;
  return 0;
}
