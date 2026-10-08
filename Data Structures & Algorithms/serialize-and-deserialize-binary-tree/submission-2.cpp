class Codec {
public:

    void pre(TreeNode* root, string &s)
    {
        if(root == NULL)
        {
            s += "N ";
            return;
        }

        s += to_string(root->val);
        s += " ";

        pre(root->left, s);
        pre(root->right, s);
    }

    string serialize(TreeNode* root)
    {
        string s = "";

        pre(root, s);

        return s;
    }

    TreeNode* build(vector<string>& v, int &idx)
    {
        if(v[idx] == "N")
        {
            idx++;
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(v[idx]));
        idx++;

        root->left = build(v, idx);
        root->right = build(v, idx);

        return root;
    }

    TreeNode* deserialize(string data)
    {
        if(data == "")
            return NULL;

        stringstream ss(data);

        vector<string> v;
        string x;

        while(ss >> x)
        {
            v.push_back(x);
        }

        int idx = 0;

        return build(v, idx);
    }
};