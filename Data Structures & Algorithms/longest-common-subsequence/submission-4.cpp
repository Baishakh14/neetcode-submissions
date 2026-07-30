#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int dp[1005][1005];
int find(int i,int j,string &a,string &b)
{
    if(i == a.size() || j == b.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = 0;
    if(a[i] == b[j]) ans = 1 + find(i+1,j+1,a,b);
    else{
        int one = find(i + 1,j,a,b);
        int two = find(i,j+1,a,b);
        int three = find(i+1,j+1,a,b);
        ans = max({ans,one,two,three});
    }
    return dp[i][j] = ans;
}
    int longestCommonSubsequence(string a, string b) {
        memset(dp,-1,sizeof(dp));
        return find(0,0,a,b);
    }
};
