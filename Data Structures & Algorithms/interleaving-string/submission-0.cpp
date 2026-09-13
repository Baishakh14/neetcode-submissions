class Solution {
public:
vector<vector<int>>dp;
string a,b,s;
int find(int aind,int bind,int ind,int chal)
{
  if(aind == a.size() && bind == b.size() && ind == s.size())
  {
    return true;
  }
  if(dp[aind][bind] != -1) return dp[aind][bind];
  bool ans = false;
  int ii = ind;
  if(chal == 0)
  {
    if(a[aind] != s[ind]) return dp[aind][bind] = false;
    for(int i = aind;i<a.size();i++)
    {
      if(a[i] != s[ii]) break;
      ans |= find(i+1,bind,ii+1,chal ^ 1);
      ii++;
      if(ii == s.size()) break;
    }
  }
  else 
  {
    if(b[bind] != s[ind]) return dp[aind][bind] = false;
    for(int i = bind;i<b.size();i++)
    {
      if(b[i] != s[ii]) break;
      ans |= find(aind,i+1,ii+1,chal ^ 1);
      ii++;
    }
  }
  return dp[aind][bind] = ans;
}
    bool isInterleave(string s1, string s2, string s3) {
    a = s1;
    b = s2;
    s = s3;
    dp.assign(110,vector<int>(110,-1));
    bool ans = false;
    ans |= find(0,0,0,0);
    dp.assign(110,vector<int>(110,-1));
    ans |= find(0,0,0,1);
    return ans;
    }
};
