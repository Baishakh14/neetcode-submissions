class Solution {
public:
vector<vector<int>>ans;
vector<int>now;
int n;
void find(int ind,vector<int>&nums)
{
    ans.push_back(now);
    if(ind == n) return;
    for(int i = ind;i<n;i++)
    {
        if(i > ind && nums[i] == nums[i-1]) continue;
        else 
        {
            now.push_back(nums[i]);
            find(i + 1,nums);
            now.pop_back();
        }
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n = nums.size();
        find(0,nums);
        return ans;
    }
};
