class Solution {
public:
static const int inf = 1e9;
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                int ti = grid[i][j];
                if(ti == 0) grid[i][j] = -inf;
                if(ti == 2) grid[i][j] = 0,q.push({i,j});
                if(ti == 1) grid[i][j] = inf;
            }
        }
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<pair<int,int>>movement = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty())
        {
            auto xy = q.front();
            q.pop();
            vis[xy.first][xy.second] = true;
            for(auto it : movement)
                {
                    int x = xy.first + it.first;
                    int y = xy.second + it.second;
                    if(x < 0 || y < 0 || x >= n || y >= m || vis[x][y]
                        || grid[x][y] == 0 || grid[x][y] == -inf) continue;
                    q.push({x,y});
                    vis[x][y] = 1;
                    grid[x][y] = min(grid[x][y],grid[xy.first][xy.second] + 1);
                }
        }
        int ans = 0;
        bool find = true;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == inf) find = false;
                else
                ans = max(ans,grid[i][j]);
            }
        }
        if(!find) return -1;
        else return ans;
    }
};
