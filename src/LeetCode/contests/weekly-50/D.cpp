#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
  bool judgePoint24(vector<int>& nums) {
    sort(begin(nums), end(nums));
    
    while (next_permutation(begin(nums), end(nums))) {
      for (int a = 0; a < 3; ++a)
      for (int b = 0; b < 2; ++b)
      for (int op1 = 0; op1 < 4; ++op1)
      for (int op2 = 0; op2 < 4; ++op2)
      for (int op3 = 0; op3 < 4; ++op3)
      {
        // Step 1
        long double x1, x2, x3, y1, y2, z;
        if (a == 0) {
          x1 = operate(nums[0], nums[1], op1);
          x2 = nums[2];
          x3 = nums[3];
          // Step 2
          if (b == 0) {
            y1 = operate(x1, x2, op2);
            y2 = x3;
            z = operate(y1, y2, op3);
          } else {
            y1 = x1;
            y2 = operate(x2, x3, op3);
            z = operate(y1, y2, op2);
          }
          
        } else if (a == 1) {
          x1 = nums[0];
          x2 = operate(nums[1], nums[2], op2);
          x3 = nums[3];
          // Step 2
          if (b == 0) {
            y1 = operate(x1, x2, op1);
            y2 = x3;
            z = operate(y1, y2, op3);
          } else {
            y1 = x1;
            y2 = operate(x2, x3, op3);
            z = operate(y1, y2, op1);
          }
          
        } else {
          x1 = nums[0];
          x2 = nums[1];
          x3 = operate(nums[2], nums[3], op3);
          // Step 2
          if (b == 0) {
            y1 = operate(x1, x2, op1);
            y2 = x3;
            z = operate(y1, y2, op2);
          } else {
            y1 = x1;
            y2 = operate(x2, x3, op2);
            z = operate(y1, y2, op1);
          }
        }
        
        if (fabs(z-24) < 1e-5) return true;
      }
    }
    
    return false;
  }
  
  double operate(double a, double b, int op) {
    if (op == 0) return a + b;
    if (op == 1) return a - b;
    if (op == 2) return a * b;
    return (b == 0 ? numeric_limits<double>::quiet_NaN() : a / b);
  }
};

int main() {
  Solution s;
  vector<int> a {4, 1, 8, 7};
  vector<int> b {1, 2, 1, 2};
  cout << s.judgePoint24(a) << endl;
  cout << s.judgePoint24(b) << endl;
  return 0;
}
