// https://leetcode.com/contest/leetcode-weekly-contest-52/problems/repeated-string-match/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int repeatedStringMatch(string A, string B) {
    int n = A.size(), m = B.size();
    int nTimes = 2 * (m / n) + 2;
    
    string a(n * nTimes, ' ');
    for (int i = 0; i < (int)a.size(); ++i) a[i] = A[i%n];
    
    auto pos = a.find(B);
    if (pos == string::npos) return -1;
    auto endpos = pos+m-1;
    return (endpos / n) + 1;
  }
};

int main() {
  Solution s;
  cout << s.repeatedStringMatch("abcd", "cdabcdab") << endl;
  return 0;
}
