class Solution {
public:
    int minCostClimbingStairs(vector<int>&dp) 
    {
    int n = dp.size();
    dp.push_back(0);
  for(int i = 2;i<=n;i++)
  {
    int x = dp[i] + dp[i-1];
    int y = dp[i] + dp[i-2];
    dp[i] = min(x,y);
  }
  return dp[n];
    }
};
