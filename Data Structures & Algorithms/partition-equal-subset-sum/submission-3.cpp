#include<bits/stdc++.h>
int dp[100005];
class Solution {
public:
    bool canPartition(vector<int>& nums) {
    memset(dp,0,sizeof(dp));
    int sum = accumulate(nums.begin(),nums.end(),0);
    if(sum & 1) return false;
    int mid = sum / 2;
    dp[0] = 1;
    for(auto it : nums)
    {
        for(int i = mid;i>=it;i--)
        {
            if(dp[i - it]) dp[i] = 1;
        }
    }
    return dp[mid];
    }
};
