#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<pair<int,int>>movement = {{1,0},{-1,0},{0,1},{0,-1}};
const int mx = 101;
bool vis[mx][mx];
void dfs(int x,int y,vector<vector<char>>&grid)
{
    vis[x][y] = true;
    for(auto it : movement)
    {
        int xx = x + it.first;
        int yy = y + it.second;
        if(xx >= 0 && yy >= 0 && xx < n && yy < m && 
           vis[xx][yy] == false && grid[xx][yy] == '1')
           dfs(xx,yy,grid);
    }
}
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(vis,false,sizeof(vis));
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == '1' && !vis[i][j])
                {
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};
