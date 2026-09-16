class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        if(nums[0] == 0) return false;
        vector<int>pre(n,0);
        for(int i = 0;i<n-1;i++)
        {
            int x = nums[i];
            if(x > 0)
            {
                pre[i+1] += 1;
                if(i + x + 1 < n) pre[i + x + 1] -= 1;
            }
        }
        for(int i = 1;i<n;i++) pre[i] += pre[i-1];
        bool ans = true;
        for(int i = 1;i<n;i++) if(pre[i] == 0) ans = false;
        return ans;
    }
};
