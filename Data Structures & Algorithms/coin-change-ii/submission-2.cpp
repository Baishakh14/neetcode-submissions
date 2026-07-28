#include<bits/stdc++.h>
#define ll long long int
const int mx = 5e3 + 5;
const int nx = 100 + 5;
ll dp[nx][mx];
class Solution {
public:
ll find(int ind,int val,vector<int>&coins,int n)
{
    if(ind == n)
    {
        if(val == 0) return 1;
        else return 0;
    }
    if(dp[ind][val] != -1) return dp[ind][val];
    ll take = 0;
    take = find(ind + 1,val,coins,n);
    ll ntt = 0;
    if(coins[ind] <= val) ntt = find(ind,val - coins[ind],coins,n);
    return dp[ind][val] = (take + ntt);
}
    int change(int amount, vector<int>& coins) {
    int n = coins.size();
    memset(dp,-1,sizeof(dp));
    return find(0,amount,coins,n);
    }
};
