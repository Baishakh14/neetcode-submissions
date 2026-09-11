class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
    s = '1' + s;
    int len = s.size();
    vector<int>dp(len,0);
    dp[0] = 1;
    for(int i = 1;i<len;i++)
    {
      for(auto it : wordDict)
      {
        int now = it.size();
        if(i - now + 1 >= 1)
        {
          now = i - now + 1;
          string hi = s.substr(now,it.size());
          if(hi == it && dp[now - 1]) dp[i] = true;
        }
      }
    }
    return dp[len-1];
    }
};
