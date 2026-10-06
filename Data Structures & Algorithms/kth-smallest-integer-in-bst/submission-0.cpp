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
int cnt = 0;
int val = 0;
void find(TreeNode *root,int k)
{
    if(root == NULL) return;
    find(root -> left,k);
    cnt++;
    if(cnt == k) val = root -> val;
    find(root -> right,k);
}
    int kthSmallest(TreeNode* root, int k) {
        cnt = 0;
        val = 0;
        find(root,k);
        return val;
    }
};
