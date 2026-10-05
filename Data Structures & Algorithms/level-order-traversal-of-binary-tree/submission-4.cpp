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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(root == nullptr) return ans;
        q.push(root);
        while(q.size() > 0)
        {
            vector<int>now;
            int l = q.size();
            for(int i = 0;i<l;i++)
            {
                auto it = q.front();
                q.pop();
                now.push_back(it -> val);
                if(it -> left) q.push(it -> left);
                if(it -> right) q.push(it -> right);
            }
            ans.push_back(now);
        }
        return ans;
    }
};
