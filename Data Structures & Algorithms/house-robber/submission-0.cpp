class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        vector<int>dp(n,0);
        dp[0] = nums[0];
        if(n > 1) dp[1] = nums[1],ans = max(ans,dp[1]);
        for(int i = 2;i<n;i++)
        {
            if((i-2) >= 0)
            {
                dp[i] = nums[i] + dp[i-2];
            }
            if(i-3 >= 0) dp[i] = max(dp[i],nums[i] + dp[i-3]);
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
