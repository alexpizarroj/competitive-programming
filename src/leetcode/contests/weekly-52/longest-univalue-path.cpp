// https://leetcode.com/contest/leetcode-weekly-contest-52/problems/longest-univalue-path/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int ans;
  
  int longestUnivaluePath(TreeNode* root) {
    ans = 0;
    int ret = go(root);
    ans = max(ans, ret);
    return ans;
  }
  
  int go(TreeNode* root) {
    if (root == NULL) return 0;
    
    int ret = 0;
    const int cval = root->val;
    
    if (root->left != NULL && root->right != NULL) {
      const int lval = root->left->val;
      const int rval = root->right->val;
      
      if (cval == lval && lval == rval) {
        const int ll = go(root->left), rr = go(root->right);
        ans = max(ans, ll + rr + 2);
        ret = 1+max(ll, rr);
        
      } else if (cval == lval) {
        ans = max(ans, go(root->right));
        ret = go(root->left) + 1;
        
      } else if (cval == rval) {
        ans = max(ans, go(root->left));
        ret = go(root->right) + 1;
        
      } else {
        ans = max(ans, go(root->left));
        ans = max(ans, go(root->right));
      }
      
    } else if (root->left != NULL) {
      const int lval = root->left->val;
      if (cval == lval) {
        ret = go(root->left)+1;
      } else {
        ans = max(ans, go(root->left));
      }
      
    } else if (root->right != NULL) {
      const int rval = root->right->val;
      if (cval == rval) {
        ret = go(root->right) + 1;
      } else {
        ans = max(ans, go(root->right));
      }
    }
    
    return ret;
  }
};

void test1() {
  TreeNode n1(5), n2(4), n3(5), n4(1), n5(1), n6(5);
  
  n1.left = &n2;
  n1.right = &n3;
  n2.left = &n4;
  n2.right = &n5;
  n3.right = &n6;
  
  Solution s;
  cout << s.longestUnivaluePath(&n1) << endl;
}

void test2() {
  TreeNode n1(1), n2(4), n3(5), n4(4), n5(4), n6(5);
  
  n1.left = &n2;
  n1.right = &n3;
  n2.left = &n4;
  n2.right = &n5;
  n3.left = &n6;
  
  Solution s;
  cout << s.longestUnivaluePath(&n1) << endl;
}

void test3() {
  TreeNode n1(4), n2(4), n3(4), n4(4), n5(4);
  
  n1.left = &n2;
  n1.right = &n3;
  n2.left = &n4;
  n2.right = &n5;
  
  Solution s;
  cout << s.longestUnivaluePath(&n1) << endl;
}

void test4() {
  TreeNode n1(5);
  
  Solution s;
  cout << s.longestUnivaluePath(&n1) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  test1();
  test2();
  test3();
  test4();
  
  return 0;
}
