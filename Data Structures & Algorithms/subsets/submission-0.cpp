class Solution {
public:
vector<vector<int>>ans;
vector<int>temp;
void find(int ind,vector<int> &nums)
{
    if(ind == nums.size())
    {
        ans.push_back(temp);
        return;
    }
    find(ind + 1,nums);
    temp.push_back(nums[ind]);
    find(ind + 1,nums);
    temp.pop_back();
}
    vector<vector<int>> subsets(vector<int>& nums) {
        find(0,nums);
        return ans;
    }
};
