#include<bits/stdc++.h>
using namespace std;
const int mx = 101;
map<pair<int,int>,int>sz;
map<pair<int,int>,pair<int,int>>parent;
bool vis[mx][mx];
int n,m;
pair<int,int>find(int x,int y)
{
    if(parent[{x,y}] == pair<int,int>{x,y}) return {x,y};
    auto it = parent[{x,y}];
    return parent[{x,y}] = find(it.first,it.second);
}
void dsu(int x,int y,int i,int j)
{
    if(find(x,y) == find(i,j)) return;
    auto ff = find(x,y);
    auto ss = find(i,j);
    if(sz[ss] > sz[ff]) swap(ff,ss);
    sz[ff] += sz[ss];
    parent[ss] = ff;
}
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        memset(vis,false,sizeof(vis));
        parent.clear();
        sz.clear();
        n = grid.size();
        m = grid[0].size();
        vector<pair<int,int>>movement = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                sz[{i,j}] = 1;
                parent[{i,j}] = {i,j};
                vis[i][j] = false;
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == '0') continue;
                vis[i][j] = true;
                for(auto it : movement)
                {
                    int x = it.first + i;
                    int y = it.second + j;
                    if(x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == '1')
                       {
                          vis[x][y] = true;
                          dsu(x,y,i,j);
                       }
                }
            }
        }
        for(auto it : parent)
        {
            if(it.first == it.second)
            {
                int x = it.first.first;
                int y = it.first.second;
                if(vis[x][y]) ans++;
            }
        }
        return ans;
    }
};
