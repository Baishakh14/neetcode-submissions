class Solution {
public:
vector<vector<int>>dp;
static const int mx = 110;
int n,m;
vector<pair<int,int>>movement = {{1,0},{-1,0},{0,1},{0,-1}};
int find(int i,int j,vector<vector<int>>&ab)
{
    if(dp[i][j] != -1) return dp[i][j];
    int now = 0;
    int final = 1;
    for(auto it : movement)
    {
        int xx = i + it.first;
        int yy = j + it.second;
        if(xx >= 0 && xx < n && yy >=0 && yy < m && ab[xx][yy]
           > ab[i][j])
           {
               now = 1 + find(xx,yy,ab);
               final = max(final,now);
           }
    }
    return dp[i][j] = final;

}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        dp.assign(mx,vector<int>(mx,-1));
        n = matrix.size();
        m = matrix[0].size();
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                ans = max(ans,find(i,j,matrix));
            }
        }
        return ans;
    }
};
