#include<bits/stdc++.h>
const int mx = 5;
class Solution {
public:
int n,m;
bool vis[mx][mx];
vector<pair<int,int>>jabo = {{1,0},{-1,0},{0,1},{0,-1}};
string s;
bool find(int i,int j,int ind,vector<vector<char>>& board)
{
  int nn,mm;
  if(ind == s.size()) return true;
  for(auto it : jabo)
  {
    nn = i + it.first;
    mm = j + it.second;
    if((nn >= 0) && (nn < n) && (mm >= 0) && (mm < m) && 
    board[nn][mm] == s[ind] && !vis[nn][mm])
    {
      vis[nn][mm] = 1;
      if(find(nn,mm,ind + 1,board)) return true;
      vis[nn][mm] = 0;
    }
  }
  return false;
}
    bool exist(vector<vector<char>>& board, string word) {
    s = word;
    n = board.size();
    m = board[0].size();
  memset(vis,0,sizeof(vis));
  bool ans = false;
  for(int i = 0;i<n;i++)
  {
    for(int j = 0;j<m;j++)
    {
      if(board[i][j] == s[0])
      {
        vis[i][j] = 1;
        if(find(i,j,1,board)) 
        {
            ans = true;
            break;
        }
        vis[i][j] = 0;
      }
    }
    if(ans) break;
  }
  return ans;
    }
};
