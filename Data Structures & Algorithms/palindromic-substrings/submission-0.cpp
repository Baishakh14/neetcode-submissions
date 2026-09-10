class Solution {
public:
    int countSubstrings(string s) {
    int n = s.size();
    int ans = 0;
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int i = n-1;i>=0;i--)
    {
      dp[i][i] = 1;
      if(i + 1 < n && s[i] == s[i+1])
      {
        dp[i][i+1] = 1;
      }
      for(int j = i+2;j<n;j++)
      {
        if(s[i] == s[j] && dp[i+1][j-1] == 1) dp[i][j] = 1;
      }
    }
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(dp[i][j] == 1) ans++;
        }
    }
    return ans;
    }
};
