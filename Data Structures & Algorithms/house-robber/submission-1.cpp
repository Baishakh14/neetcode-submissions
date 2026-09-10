class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        multiset<int,greater<int>>st;
        st.insert(0);
        st.insert(nums[0]);
        int ans = nums[1];
        vector<int>dp(n,0);
        dp[0] = nums[0];
        for(int i = 1;i<n;i++)
        {
            int now = dp[i-1];
            st.erase(st.find(now));
            dp[i] = nums[i] + *st.begin();
            st.insert(now);
            st.insert(dp[i]);
        }
        return *st.begin();
    }
};
