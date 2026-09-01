class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n,m;
        n = heights.size();
        m = heights[0].size();
        vector<vector<int>>vis1(n,vector<int>(m,0)); /// ul check
        vector<vector<int>>vis2(n,vector<int>(m,0)); /// dr check
        queue<pair<int,int>>q,qq;
        vector<pair<int,int>>movement = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i = 0;i<n;i++)
        {     
            q.push({i,0});
            vis1[i][0] = 1;
            vis2[i][m-1] = 1;
            qq.push({i,m-1});
        }
        for(int i = 0;i<m;i++)
        {
            q.push({0,i});
            vis1[0][i] = 1;
            vis2[n-1][i] = 1;
            qq.push({n-1,i});
        }
        while(!q.empty())
        {
            auto xy = q.front();
            q.pop();
            for(auto it : movement)
            {
                int x = xy.first + it.first;
                int y = xy.second + it.second;
                if(x >= 0 && y >= 0 && x < n && y < m && !vis1[x][y]
                   && heights[x][y] >= heights[xy.first][xy.second])
                   {
                    q.push({x,y});
                    vis1[x][y] = 1;
                   }
            }
        }
        while(!qq.empty())
        {
            auto xy = qq.front();
            qq.pop();
            for(auto it : movement)
            {
                int x = xy.first + it.first;
                int y = xy.second + it.second;
                if(x >= 0 && y >= 0 && x < n && y < m && !vis2[x][y]
                   && heights[x][y] >= heights[xy.first][xy.second])
                   {
                    qq.push({x,y});
                    vis2[x][y] = 1;
                   }
            }
        }
        vector<vector<int>>ans;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(vis1[i][j] && vis2[i][j])
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
