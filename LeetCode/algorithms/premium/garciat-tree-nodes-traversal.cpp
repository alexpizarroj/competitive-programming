#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int closestValue(TreeNode* root, double target) {
    return closestValueImpl(root, target, root->val);
  }
  
private:
  int closestValueImpl(TreeNode* root, double target, int bestSoFar) {
    if (!root) return bestSoFar;
    
    if (fabs(target - bestSoFar) > fabs(target - root->val)) {
      bestSoFar = root->val;
    }
    
    if (target <= root->val) {
      return closestValueImpl(root->left, target, bestSoFar);
    }
    return closestValueImpl(root->right, target, bestSoFar);
  }
};
 
int main() {
  TreeNode root(10);
  root.left = new TreeNode(8);
  root.right = new TreeNode(12);
  
  Solution s;
  cout << s.closestValue(&root, 11) << endl;
  
  return 0;
}
