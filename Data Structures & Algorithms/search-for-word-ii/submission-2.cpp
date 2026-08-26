#include<bits/stdc++.h>
using namespace std;
vector<string>ans;
int n,m;
const int mx = 13;
bool vis[mx][mx];
vector<pair<int,int>>movement = {{1,0},{-1,0},{0,1},{0,-1}};
string s;
struct node
{
    int count;
    node *next[26];
};
node *create()
{
    node *now = new node;
    now -> count = 0;
    for(int i = 0;i<26;i++)
    {
        now -> next[i] = nullptr;
    }
    return now;
}
void add(string s,node *root)
{
    node *now = root;
    for(auto it : s)
    {
        int ind = it - 'a';
        if(now -> next[ind] == nullptr) now -> next[ind] = create();
        now = now -> next[ind];
    }
    now -> count++;
}
bool search(string s,node *root)
{
    node *now = root;
    for(auto it : s)
    {
        int ind = it - 'a';
        if(now -> next[ind] == nullptr) return false;
        now = now -> next[ind];
    }
    if(now -> count > 0) return true;
    return false;
}
void find(node *root,int x,int y,vector<vector<char>>& board)
{
    if(root -> count > 0)
    {
        ans.push_back(s);
        root -> count--;
    }
    node *now = root;
    int ind;
    for(auto it : movement)
    {
        int i = it.first;
        int j = it.second;
        if(x + i < n && x + i >= 0 && y + j < m && y + j >= 0 &&
        vis[x+i][y+j] == 0)
        {
            ind = board[x+i][y+j] - 'a';
            if(now -> next[ind] != nullptr)
            {
               s.push_back(board[x+i][y+j]);
               vis[x+i][y+j] = 1;
               find(now -> next[ind],x+i,y+j,board);
               vis[x+i][y+j] = 0;
               s.pop_back();
            }
        }
    }
}
class Solution {
public:
vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
 {
    node *root = create();
    ans.clear();
    for(auto it : words) add(it,root);
    n = board.size();
    m = board[0].size();
    memset(vis,false,sizeof(vis));
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            int ind = board[i][j] - 'a';
            if(root -> next[ind] != nullptr)
            {
                vis[i][j] = 1;
                s.push_back(board[i][j]);
                find(root -> next[ind],i,j,board);
                vis[i][j] = 0;
                s.pop_back();
            }
        }
    }
    return ans;
 }
};
