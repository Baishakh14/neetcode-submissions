#include<bits/stdc++.h>
#define ll long long int
static const int mx = 5e3 + 10;
ll dp[mx];
class Solution {
public:
    int change(int amount, vector<int>& coins) {
    int n = coins.size();
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(auto it : coins)
    {
        for(int i = it;i<=amount;i++)
        {
            dp[i] = (dp[i] + dp[i - it]);
        }
    }
    return dp[amount];
    }
};
