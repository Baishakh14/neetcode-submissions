class Solution {
public:
static const int mx = 100;
vector<vector<int>>dp;
string a,b;
bool find(int i,int j)
{
    if(dp[i][j] != -1) return dp[i][j];
    if(j == b.size()) 
    {
        if(i == a.size()) return true;
        else return false;
    }
    bool ans = false;
    bool ok = false;
    if(i < a.size() && (a[i] == b[j] || b[j] == '.')) 
    ok = true;
    if(j + 1 < b.size() && b[j+1] == '*')
    {
        ans |= find(i,j+2);
        if(ok) ans |= find(i + 1,j);
    }
    else 
    {
        if(ok) ans |= find(i + 1,j + 1);
    }
    return dp[i][j] = ans;
}
    bool isMatch(string s, string p) {
       a = s,b = p;
       dp.assign(mx,vector<int>(mx,-1));
       return find(0,0);
    }
};
