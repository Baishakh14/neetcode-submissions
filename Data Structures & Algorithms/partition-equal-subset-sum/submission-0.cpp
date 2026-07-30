#include<bits/stdc++.h>
int dp[105][100005];
class Solution {
public:
bool find(int ind,int val,vector<int>&nums)
{
    if(val == 0) return 1;
    if(ind == nums.size()) return 0;
    if(dp[ind][val] != -1) return dp[ind][val];
    int hobe = 0;
    hobe |= find(ind + 1,val,nums);
    if(nums[ind] <= val)
    {
        hobe |= find(ind + 1,val - nums[ind],nums);
    }
    return dp[ind][val] = hobe;
}
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum & 1) return 0;
        int mid = sum / 2;
        memset(dp,-1,sizeof(dp));
        return find(0,mid,nums);
    }
};
