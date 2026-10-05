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
        map<int,vector<int>>fre;
        queue<pair<int,TreeNode *>>q;
        vector<vector<int>>ans;
        if(root == NULL) return ans;
        q.push({0,root});
        while(!q.empty())
        {
            auto it = q.front();
            fre[it.first].push_back(it.second -> val);
            q.pop();
            TreeNode *now = it.second;
            if(now -> left != NULL) q.push({it.first + 1,now -> left});
            if(now -> right != NULL) q.push({it.first + 1,now -> right});
        }
        for(auto it : fre)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
