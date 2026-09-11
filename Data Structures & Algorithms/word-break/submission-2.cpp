class Solution {
public:
vector<int>dp;
bool find(int ind,string s,vector<string>&ab)
{
  if(ind == s.size()) return true;
  if(dp[ind] != -1) return dp[ind];
  bool ans = false;
  for(auto it : ab)
  {
    string now = it;
    if(ind + now.size() <= s.size())
    {
      string hi = s.substr(ind,now.size());
      if(hi == it)
      {
        ans |= find(ind + hi.size(),s,ab);
      }
    }
  }
  return dp[ind] = ans;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
    dp.assign(len,-1);
    bool ans = find(0,s,wordDict);
    return ans;
    }
};
