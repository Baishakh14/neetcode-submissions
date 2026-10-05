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
int ans = 0;
void dfs(TreeNode *root,int cmax)
{
    if(root -> val >= cmax) ans++;
    if(root -> left) dfs(root -> left,max(cmax,root -> val));
    if(root -> right) dfs(root -> right,max(cmax,root -> val));
}
    int goodNodes(TreeNode* root) {
        ans = 0;
        dfs(root,INT_MIN);
        return ans;
    }
};
