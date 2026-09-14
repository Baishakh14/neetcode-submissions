class Solution {
public:
static const int mx = 1e2 + 10;
vector<vector<int>>dp;
int find(int i,int j,string &a,string &b)
{
    if(i == a.size() && j == b.size()) return 0;
    if(i == a.size())
    {
        return b.size() - j;
    }
    if(j == b.size())
    {
        return a.size() - i;
    }
    if(dp[i][j] != -1) return dp[i][j];
    int now = INT_MAX;
    if(a[i] == b[j])
    {
        now = min(now,find(i + 1,j + 1,a,b));
    }
    else 
    {
        now = min(now,1 + find(i,j + 1,a,b));
        now = min(now,1 + find(i + 1,j,a,b));
        now = min(now,1 + find(i +1,j+1,a,b));
    }
    return dp[i][j] = now;
}
    int minDistance(string word1, string word2) {
        dp.assign(mx,vector<int>(mx,-1));
        return find(0,0,word1,word2);
    }
};
