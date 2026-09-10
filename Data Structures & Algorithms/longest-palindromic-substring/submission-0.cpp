class Solution {
public:
    string longestPalindrome(string s) {
    int n = s.size();
    int ans = 1;
    int l = 0,r = 0;
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int i = n-1;i>=0;i--)
    {
      dp[i][i] = 1;
      if(i + 1 < n && s[i] == s[i+1])
      {
        dp[i][i+1] = 1;
        if(ans < 2)
        {
          ans = 2;
          l = i,r = i + 1;
        }
      }
      for(int j = i+2;j<n;j++)
      {
        if(s[i] == s[j] && dp[i+1][j-1] == 1)
        {
          dp[i][j] = 1;
          int len = j - i + 1;
          if(len > ans)
          {
            ans = len;
            l = i,r = j;
          }
        }
      }
    }
    string final = "";
    for(int i = l;i<=r;i++) final.push_back(s[i]);
    return final;
    }
};
