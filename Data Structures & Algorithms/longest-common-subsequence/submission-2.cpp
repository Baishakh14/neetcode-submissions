#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int dp[1005][1005];
    int longestCommonSubsequence(string a, string b) {
        a = '1' + a;
        b = '1' + b;
        int n = a.size();
        int m = b.size();
        memset(dp,0,sizeof(dp));
    for(int i = 1;i<n;i++)
    {
        for(int j = 1;j<m;j++)
        {
            if(a[i] == b[j]) dp[i][j] = 1 + dp[i-1][j-1];
            else 
            {
                int one = dp[i-1][j];
                int two = dp[i][j-1];
                int three = dp[i-1][j-1];
                dp[i][j] = max({one,two,three});
            }
        }
    }
    return dp[n-1][m-1];
    }
};
