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
        void find(TreeNode *root , int tar,unordered_set<int>&st,vector<int>&hi)
        {
            while(root != NULL)
            {
                st.insert(root -> val);
                hi.push_back(root -> val);
                if(root -> val == tar) break;
                if(tar > root -> val) root = root -> right;
                else root = root -> left;
            }
        }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_set<int>a,b;
        vector<int>aa,bb;
        find(root,p -> val,a,aa);
        find(root,q -> val,b,bb);
        int now = 0;
        for(auto it : aa)
        {
            if(b.count(it)) now = it;
        }
        while(root != NULL)
        {
            if(root -> val == now) return root;
            if(now > root -> val) root = root -> right;
            else root = root -> left; 
        }
    }
};
