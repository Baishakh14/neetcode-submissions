class Solution {
public:
unordered_map<int,unordered_map<int,int>>dp;
int find(int ind,int sum,int tar,vector<int>& nums)
{
  if(ind == nums.size()) 
  {
    if(sum == tar) return 1;
    else return 0;
  }
  if(dp[ind].count(sum)) return dp[ind][sum];
  int now = sum + nums[ind];
  int now2 = sum - nums[ind];
  int total = 0;
  total += find(ind + 1,now,tar,nums);
  total += find(ind + 1,now2,tar,nums);
  return dp[ind][sum] = total;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        dp.clear();
        return find(0,0,target,nums);
    }
};
