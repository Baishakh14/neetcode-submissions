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

class Codec {
public:
   void pre(TreeNode *root , string &s)
   {
    if(root == NULL)
    {
        s += ("N ");
        return;
    }
    int val = root -> val;
    string now = to_string(val);
    s += now;
    s.push_back(' ');
    pre(root -> left,s);
    pre(root -> right,s);
   }
  TreeNode *bana(string &s,int &ind)
  {
    string now = "";
    while(s[ind] != ' ') 
    {
        now.push_back(s[ind]);
        ind++;
    }
    ind++;
    if(now == "N")
    return NULL;
    int val = stoi(now);
    TreeNode *root = new TreeNode(val);
    root -> left = bana(s,ind);
    root -> right = bana(s,ind);
    return root;
  }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        pre(root,s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int ind = 0;
        return bana(data,ind);
    }
};
