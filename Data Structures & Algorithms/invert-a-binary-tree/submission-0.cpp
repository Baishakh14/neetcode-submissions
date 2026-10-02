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
void ans(TreeNode *now)
{
    if(now == NULL) return;
        ans(now -> left);
        ans(now -> right);
        swap(now -> left,now -> right);
}
    TreeNode* invertTree(TreeNode* root) {
        ans(root);
        return root;
    }
};
