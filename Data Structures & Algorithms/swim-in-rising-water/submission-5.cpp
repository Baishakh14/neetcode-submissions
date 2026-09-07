class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int mn = INT_MAX;
        int mx = INT_MIN;
        int n = grid.size();
        for(int i = 0;i<n;i++)
        {
          for(int j = 0;j<n;j++)
          {
            mn = min(mn,grid[i][j]);
            mx = max(mx,grid[i][j]);
          }
        }
        mn = max(mn,grid[0][0]);
        int ans = mx;
      vector<pair<int,int>>movement = {{1,0},{-1,0},{0,1},{0,-1}};
        while(mn <= mx)
        {
          int mid = (mn + mx) / 2;
          vector<vector<int>>vis(n,vector<int>(n,0));
          queue<pair<int,int>>q;
          q.push({0,0});
          vis[0][0] = 1;
          while(!q.empty())
          {
            auto now = q.front();
            int x = now.first;
            int y = now.second;
            q.pop();
            for(auto it : movement)
            {
              int xx = it.first + x;
              int yy = it.second + y;
              if(xx >= 0 && yy >= 0 && xx<n && yy<n)
              {
                if(!vis[xx][yy] && grid[xx][yy] <= mid)
                {
                  q.push({xx,yy});
                  vis[xx][yy] = 1;
                }
              }
            }
          }
          if(vis[n-1][n-1] == 1)
          {
            ans = mid;
            mx = mid - 1;
          }
          else mn = mid + 1;
        }
        return ans;
    }
};
