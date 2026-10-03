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
bool find(TreeNode *p,TreeNode *q)
{
    if(p == NULL && q == NULL) return true;
    if((p == NULL && q != NULL) || (q == NULL && p != NULL)) return false;
    if(p -> val != q -> val) return false;
    bool ans = true; 
    ans &= find(p -> left,q -> left);
    ans &= find(p -> right,q -> right);
    return ans;
}
bool st(TreeNode *root,TreeNode *sr)
{
    bool ans = false;
    if(root == NULL) return false;
    if(root -> val == sr -> val)
    {
        ans |= find(root,sr);
    }
    ans |= st(root -> left,sr);
    ans |= st(root -> right,sr);
    return ans;
}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return st(root,subRoot);
    }
};
