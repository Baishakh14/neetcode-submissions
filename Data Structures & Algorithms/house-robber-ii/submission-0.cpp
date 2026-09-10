class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        vector<int>dp(n,0);
        dp[0] = nums[0];
        for(int i = 1;i<n-1;i++)
        {
            dp[i] = nums[i];
            if((i-2) >= 0)
            {
                dp[i] = nums[i] + dp[i-2];
            }
            if(i-3 >= 0) dp[i] = max(dp[i],nums[i] + dp[i-3]);
            ans = max(ans,dp[i]);
        }
        if(n == 1) return ans;
        dp.assign(n,0);
        int ans2 = nums[1];
        dp[1] = nums[1];
        for(int i = 2;i<n;i++)
        {
            dp[i] = nums[i];
            if((i-2) >= 1)
            {
                dp[i] = nums[i] + dp[i-2];
            }
            if(i-3 >= 1) dp[i] = max(dp[i],nums[i] + dp[i-3]);
            ans2 = max(ans2,dp[i]);
        }
        return max(ans,ans2);
    }
};
