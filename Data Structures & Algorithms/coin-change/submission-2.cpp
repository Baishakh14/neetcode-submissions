#include<bits/stdc++.h>
class Solution {
public:
#define ll long long int
static const int mx = 1e5 + 10;
ll dp[mx];
int find(int val,vector<int>&coins,int n)
{
    if(val == 0) return dp[val] = 0;
    if(dp[val] != -1) return dp[val];
    ll cnt = INT_MAX;
    for(int i = 0;i<n;i++)
    {
        if(val >= coins[i])
        {
            cnt = min(cnt,1LL + find(val - coins[i],coins,n));
        }
    }
    return dp[val] = cnt;
}
    int coinChange(vector<int>& coins, int amount) 
    {
    int n;
    n = coins.size();
    memset(dp,-1,sizeof(dp));
    find(amount,coins,n);
    ll ans = dp[amount];
    if(ans >= INT_MAX) return -1;
    else return ans;
    }
};
