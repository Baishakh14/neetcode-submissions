class Solution {
public:
    int numDecodings(string s) {
    bool find = 0;
    for(int i = 1;i<s.size();i++)
    {
      string now = "";
      now.push_back(s[i-1]);
      now.push_back(s[i]);
      if(now == "00") find = true;
      if(s[i] == '0' && s[i-1] > '2') find = true;
    }
    if(find || s[0] == '0')
    {
      return 0;
    }
    int n = s.size();
    vector<int>dp(n,0);
    if(n == 1)
    {
      return 1;
    }
    if(s[n-1] != '0') dp[n-1] = 1;
    if(s[n-2] != '0') 
    {
      string now = "";
      now.push_back(s[n-2]);
      now.push_back(s[n-1]);
      if(now <= "26") dp[n-2] = dp[n-1] + 1;
      else dp[n-2] = 1;
    }
    for(int i = n-3;i>=0;i--)
    {
      if(s[i] == '0') dp[i] = 0;
      else 
      {
        if(s[i+1] == '0') dp[i] = max(dp[i+1],dp[i+2]);
        else{
          string now = "";
          now.push_back(s[i]);
          now.push_back(s[i+1]);
          if(now < "27") dp[i] = dp[i+1] + dp[i+2];
          else 
          dp[i] = max(dp[i+1],dp[i+2]);
        }
      }
    }
    return dp[0];
    }
};
