class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n * (n+1)) / 2;
        int ans = 0;
        for(auto it : nums) ans += it;
        return sum - ans;
    }
};
