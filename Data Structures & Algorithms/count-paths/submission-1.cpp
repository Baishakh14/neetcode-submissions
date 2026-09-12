class Solution {
public:
vector<vector<int>>dp;
int find(int i,int j,int n,int m)
{
    if(i == n-1 && j == m-1) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = 0;
    if(i + 1 < n) ans += find(i + 1,j,n,m);
    if(j + 1 < m) ans += find(i,j+1,n,m);
    return dp[i][j] = ans;
}
    int uniquePaths(int m, int n) {
        dp.assign(m,vector<int>(n,-1));
        return find(0,0,m,n);
    }
};
