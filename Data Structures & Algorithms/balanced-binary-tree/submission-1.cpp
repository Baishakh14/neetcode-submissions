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
 bool ans;
int find(TreeNode *root)
 {
    if(root == NULL) return 0;
    int left = 0;
    int right = 0;
    left = 1 + find(root -> left);
    right = 1 + find(root -> right);
    if(abs(left - right) > 1) ans = false;
    return max(left,right);
 }
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        ans = true;
        find(root);
        return ans;
    }
};
