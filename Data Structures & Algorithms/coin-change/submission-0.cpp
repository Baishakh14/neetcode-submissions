class Solution {
public:
#define ll long long int
static const int mx = 1e5 + 10;
ll dp[mx];
    int coinChange(vector<int>& coins, int amount) 
    {
    int n;
    n = coins.size();
    for(int j = 0;j<mx;j++) dp[j] = INT_MAX;
    dp[0] = 0;
    for(int i = 1;i<=amount;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(coins[j] <= i)
            {
                dp[i] = min(dp[i],dp[i - coins[j]] + 1);
            }
        }
       // cout<<dp[i]<<endl;
    }
    return (dp[amount] >= INT_MAX?-1:dp[amount]);
    }
};
