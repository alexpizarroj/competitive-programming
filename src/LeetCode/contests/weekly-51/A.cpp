#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

class Solution {
public:
  int calPoints(vector<string>& ops) {
    const int n = ops.size();
    vector<int> points;
    
    for (int i = 0; i < n; ++i) {
      int m = points.size();
      
      if (ops[i] == "+") {
        int sum = (m-1 >= 0 ? points[m-1] : 0) + (m-2 >= 0 ? points[m-2] : 0);
        points.push_back(sum);
      } else if (ops[i] == "D") {
        int sum = (m-1 >= 0 ? points[m-1] * 2 : 0);
        points.push_back(sum);
      } else if (ops[i] == "C") {
        if (m > 0) points.pop_back();
      } else {
        int sum = to_integer(ops[i]);
        points.push_back(sum);
      }
    }
    
    int ans = 0;
    for (int x : points) ans += x;
    return ans;
  }
  
private:
  int to_integer(const string &x) {
    int ret;
    sscanf(x.c_str(), "%d", &ret);
    return ret;
  }
};

int main() {
  vector<string> c1{"5","2","C","D","+"};
  vector<string> c2{"5","-2","4","C","D","9","+","+"};
  
  Solution s;
  cout << s.calPoints(c1) << endl;
  cout << s.calPoints(c2) << endl;
  
  return 0;
}
