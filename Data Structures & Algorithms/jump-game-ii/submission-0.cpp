class Solution {
public:
static const int inf = 1e4;
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,inf);
        dp[n-1] = 0;
        for(int i = n-2;i>=0;i--)
        {
            for(int j = i + 1;j<min(n,i + nums[i]+1);j++)
            {
                dp[i] = min(dp[i],1 + dp[j]);
            }
        }
        return dp[0];
    }
};
