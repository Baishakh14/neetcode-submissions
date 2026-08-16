class Solution {
public:
int bs2(vector<int>&nums,int val,int l,int r)
{
  while(l <= r)
  {
    int mid = (l + r) / 2;
    if(nums[mid] == val) return mid;
    if(nums[mid] > val) r = mid - 1;
    else l = mid + 1;
  }
  return -1;
}
int search(vector<int>& nums, int target) {
    int n = nums.size();
  int l = 1,r = n-2;
  int ans = nums[0];
  int ind = 0;
  if(nums.back() < nums[0]) ind = n-1;
  ans = min(ans,nums[n-1]);
  while(l <= r)
  {
    int mid = (l + r) / 2;
    if(nums[mid] < nums[mid+1] && nums[mid] < nums[mid - 1])
    {
      ans = nums[mid];
      ind  = mid;
      break;
    }
    if(nums[mid] > nums.back()) l = mid + 1;
    else 
    {
      if(nums[mid] < ans)
      {
        ans = nums[mid];
        ind = mid;
      }
      r = mid -  1;
    }
  }
  if(ind == n-1)
  {
    if(target == nums[ind]) return ind;
    else return bs2(nums,target,0,n-2);
  }
  else if(ind == 0)
  {
    return bs2(nums,target,0,n-1);
  }
  else 
  {
    if(target <= nums.back()) return bs2(nums,target,ind,n-1);
    else return bs2(nums,target,0,ind);
  }
    }
};
