class Solution {
public:
vector<vector<int>>ans;
vector<int>now;
void find(int ind,vector<int> &nums,int sum,int target)
{
    if(sum == target)
    {
        ans.push_back(now);
        return;
    }
    if(ind == nums.size()) return;
    if(sum > target) return;
    now.push_back(nums[ind]);
    sum += nums[ind];
    find(ind,nums,sum,target);
    sum -= nums[ind];
    now.pop_back();
    find(ind + 1,nums,sum,target);
}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        find(0,nums,0,target);
        return ans;
    }
};
