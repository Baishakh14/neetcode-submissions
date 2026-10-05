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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>ans;
        if(root == NULL) return {};
        q.push(root);
        while(!q.empty())
        {
            int l = q.size();
            int val = 0;
            for(int i = 0;i<l;i++)
            {
                auto it = q.front();
                q.pop();
                val = it -> val;
                if(it -> left) q.push(it -> left);
                if(it -> right) q.push(it -> right);
            }
            ans.push_back(val);
        }
        return ans;
    }
};
