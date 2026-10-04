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
        void find(TreeNode *root , int tar,vector<int>&hi)
        {
            while(root != NULL)
            {
                hi.push_back(root -> val);
                if(root -> val == tar) break;
                if(tar > root -> val) root = root -> right;
                else root = root -> left;
            }
        }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int>aa,bb;
        find(root,p -> val,aa);
        find(root,q -> val,bb);
        int now = 0;
        for(int i = 0;i<min(aa.size(),bb.size());i++)
        {
            if(aa[i] == bb[i]) now = aa[i];
            else break;
        }
        while(root != NULL)
        {
            if(root -> val == now) return root;
            if(now > root -> val) root = root -> right;
            else root = root -> left; 
        }
    }
};
