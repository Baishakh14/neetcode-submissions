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
    int cnt = 0;
    int left = 0,right = 0;
    left = max(left,1 + find(root -> left));
    right = max(right , 1 + find(root -> right));
    ans = max(ans,left + right);
    return max(left,right);
}
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        ans = 0;
        find(root);
        return ans - 2;
    }
};
