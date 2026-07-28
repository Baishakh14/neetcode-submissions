#include<bits/stdc++.h>
class Solution {
public:
int n;
static const int mx = 1e3 + 10;
int dp[mx];
int find(int ind,vector<int>&nums)
{
    if(dp[ind] != -1) return dp[ind];
    int ans = 1;
    for(int i = 0;i<ind;i++)
    {
        if(nums[ind] > nums[i])
        {
            ans = max(ans,1 + find(i,nums));
        }
    }
    return dp[ind] = ans;
}
    int lengthOfLIS(vector<int>& nums) {
    n = nums.size();
    for(int i = 0;i<n;i++) dp[i] = -1;
    int ans = 1;
    for(int i = 0;i<n;i++)
    {
        ans = max(ans,find(i,nums));
    }
    return ans;
    }
};