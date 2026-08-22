class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = (1 << (int)nums.size());
        vector<vector<int>>ans;
        for(int i = 0;i<n;i++)
        {
            vector<int>now;
            for(int j = 0;j<nums.size();j++)
            {
                if((1<<j) & i) now.push_back(nums[j]);
            }
            ans.push_back(now);
        }
        return ans;
    }
};
