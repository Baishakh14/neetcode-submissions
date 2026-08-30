/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
#include<bits/stdc++.h>
using namespace std;
// struct Node
// {
//     int val;
//     vector<Node*>neighbors;
// };
map<Node*,Node*>fre;
void dfs(Node *root,Node *arekta)
{
   for(auto it : root -> neighbors)
   {
    if(fre.count(it))
    {
        Node *bai = fre[it];
        arekta -> neighbors.push_back(bai);
    }
    else 
    {
        Node *onno = new Node();
        onno -> val = it -> val;
        arekta -> neighbors.push_back(onno);
        fre[it] = onno;
        dfs(it,onno);
    }
   }
}
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        Node *root = new Node();
        root -> val = node -> val;
        fre[node] = root;
        dfs(node,root);
        return root;
    }
};
