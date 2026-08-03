class Solution {
public:
vector<int>dp;
int find(int i,vector<int> &ab)
{
  if(i == 0 || i == 1) return ab[i];
  if(dp[i] != -1) return dp[i];
  return dp[i] = ab[i] + min(find(i-1,ab),find(i-2,ab));
}
    int minCostClimbingStairs(vector<int>&ab) 
    {
    int n = ab.size();
    ab.push_back(0);
    dp.assign(n+1,-1);
    return find(n,ab);
    }
};
