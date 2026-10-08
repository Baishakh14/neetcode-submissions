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
map<int,int>fre;
int ind = 0;
TreeNode *build(vector<int>&ab,int l,int r)
{
    if(l > r) return NULL;
    int val = ab[ind];
    int pos = fre[val];
    ind++;
    TreeNode *root = new TreeNode(val);
    root -> left = build(ab,l,pos-1);
    root -> right = build(ab,pos + 1,r);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        fre.clear();
        ind = 0;
        for(int i = 0;i<inorder.size();i++)
        {
            fre[inorder[i]] = i;
        }
        TreeNode *ans = build(preorder,0,inorder.size() - 1);
        return ans;
    }
};
