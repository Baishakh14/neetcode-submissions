class Solution {
public:
string a,b;
static const int mx = 1e3 + 10;
vector<vector<int>>dp;
int find(int i,int j)
{
    if(j == b.size()) return 1;
    if(i == a.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = find(i+1,j);
    if(a[i] == b[j]) 
    {
        ans = ans + find(i+1,j+1);
    }
    return dp[i][j] = ans;
}
    int numDistinct(string s, string t) {
        a = s,b = t;
        dp.assign(mx,vector<int>(mx,-1));
        return find(0,0);
    }
};
