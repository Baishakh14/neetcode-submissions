#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int n,m;
int dp[1005][1005];
int find(int i,int j,string &a,string &b)
{
    if(i == n || j == m) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = 0,first = 0,second = 0,third = 0;
    if(a[i] == b[j]) 
    ans = 1 + find(i + 1,j + 1,a,b);
    else 
    {
        first = find(i+1,j,a,b);
        second = find(i,j+1,a,b);
        third = find(i+1,j+1,a,b);
    }
    return dp[i][j] = max({ans,first,second,third});
}
    int longestCommonSubsequence(string a, string b) {
        n = a.size();
        m = b.size();
        memset(dp,-1,sizeof(dp));
        return find(0,0,a,b);
    }
};
