/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
int ans;
  int find(TreeNode *root)
  {
    if(root == NULL) return 0;
    int val = root -> val;
    int left = 0,right = 0;
    left = left + find(root -> left);
    right = right + find(root -> right);
    int now = max({val,left+val,right+val,left + right + val});
    ans = max(ans,now);  
    int fr = max({val,left + val,right + val}); /// for return;
    return fr;
  }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        find(root);
        return ans;
    }
};
