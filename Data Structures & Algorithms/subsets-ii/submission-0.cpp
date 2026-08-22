class Solution {
public:
set<vector<int>>bai;
vector<int>now;
void find(int ind,vector<int> &nums)
{
    if(ind == nums.size())
    {
        bai.insert(now);
        return;
    }
    find(ind + 1,nums);
    now.push_back(nums[ind]);
    find(ind + 1,nums);
    now.pop_back();
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        find(0,nums);
        vector<vector<int>>ans;
        for(auto it : bai)
        {
            ans.push_back(it);
        }
        return ans;
    }
};
