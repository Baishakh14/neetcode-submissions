class Solution {
public:
const int mx = 50 + 5;
vector<pair<int,int>>movement = {{1,0},{-1,0},{0,1},{0,-1}};
int cnt = 0;
void dfs(vector<vector<int>>&grid,int x,int y)
{
    cnt++;
    grid[x][y] = 0;
    for(auto it : movement)
    {
        int xx = x + it.first;
        int yy = y + it.second;
        if(xx >= 0 && yy >= 0 && xx < grid.size() && yy < grid[0].size()
           && grid[xx][yy] == 1)
           {
            dfs(grid,xx,yy);
           }
    }
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    dfs(grid,i,j);
                    ans = max(ans,cnt);
                    cnt = 0;
                }
            }
        }
        return ans;
    }
};
