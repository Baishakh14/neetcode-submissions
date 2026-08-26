#include<bits/stdc++.h>
using namespace std;
const int mx = 101;
bool vis[mx][mx];
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(vis,false,sizeof(vis));
        int ans = 0;
        vector<pair<int,int>>movement = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[i].size();j++)
            {
                if(grid[i][j] == '0' || vis[i][j]) continue;
                ans++;
                queue<pair<int,int>>q;
                q.push({i,j});
                vis[i][j] = true;
                while(!q.empty())
                {
                auto xy = q.front();
                q.pop();
                for(auto it : movement)
                {
                    int x = it.first + xy.first;
                    int y = it.second + xy.second;
                    if(x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == '1'
                       && !vis[x][y])
                       {
                        q.push({x,y});
                        vis[x][y] = true;
                       }
                }
                }
            }
        }
        return ans;
    }
};
