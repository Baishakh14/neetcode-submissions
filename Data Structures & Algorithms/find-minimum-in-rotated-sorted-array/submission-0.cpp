class Solution {
public:
    int findMin(vector<int> &nums) 
{
  int l = 1,r = nums.size()-2;
  int ans = nums[0];
  ans = min(ans,nums.back());
  while(l <= r)
  {
    int mid = (l + r) / 2;
    if(nums[mid] < nums[mid+1] && nums[mid] < nums[mid - 1])
    return nums[mid];
    if(nums[mid] > nums.back()) l = mid + 1;
    else 
    {
      ans = min(ans,nums[mid]);
      r = mid -  1;
    }
}
return ans;
    }
};
