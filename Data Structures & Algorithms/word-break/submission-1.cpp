
class Solution {
const int mx = 300;
vector<vector<int>>dp;
public:
bool find(int sind,int abind,string s,vector<string>&ab)
{
  bool ans = false;
  int n = ab.size();
  if(dp[sind][abind] != -1) return dp[sind][abind];
  if(sind == s.size()) return true;
  for(int i = 0;i<n;i++)
  {
    string &now = ab[i];
    bool ok = true;
    int iind = sind;
    for(int j = 0;j<now.size();j++)
    {
      if(iind == s.size()) dp[sind][i] = false;
      if(now[j] == s[iind]) 
      {
        iind++;
      }
      else 
      {
        ok = false;
        break;
      }
    }
    if(ok)
    {
      ans |= find(iind,i,s,ab);
    }
  }
  return dp[sind][abind] = ans;
}
    bool wordBreak(string s, vector<string>& wordDict) {
    dp.assign(mx,vector<int>(mx,-1));
    bool ans = find(0,0,s,wordDict);
    return ans;
    }
};
