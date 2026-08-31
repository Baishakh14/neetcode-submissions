#include<bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        vector<pair<int,int>>movement = {{1,0},{-1,0},{0,1},{0,-1}};
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == 0) 
                {
                q.push({i,j});
                vis[i][j] = 1;

                }
            }
        }
                while(!q.empty())
                {
                    auto xy = q.front();
                    q.pop();
                    for(auto it : movement)
                    {
                        int xx = it.first + xy.first;
                        int yy = it.second + xy.second;
                        if(xx >= 0 && xx < n && yy >= 0 && yy < m &&
                           !vis[xx][yy])
                           {
                            if(grid[xx][yy] <= grid[xy.first][xy.second] + 1)
                            continue;
                            grid[xx][yy] =grid[xy.first][xy.second] + 1;
                            vis[xx][yy] = true;
                            q.push({xx,yy});
                           }
            }
        }
        return;
    }
};
