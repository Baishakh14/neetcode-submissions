class Solution {
public:
const int inf = -1e9;
int BS(vector<int>&nums1,vector<int>&nums2,int target)
{
  int l = 0;
  int r = (int)nums1.size() - 1;
  bool find = false;
  int val;
  while(l <= r)
  {
    int mid = (l + r) / 2;
    int age = lower_bound(nums2.begin(),nums2.end(),nums1[mid]) - nums2.begin();
    int baki = upper_bound(nums2.begin(),nums2.end(),nums1[mid]) - nums2.begin();
    if(target >= (mid + age) && target <= (mid + baki))
    {
      find = true;
      val = nums1[mid];
      break;
    }
    if(mid + baki > target)
    {
      r = mid - 1;
    }
    else l = mid + 1;
  }
  if(find) return val;
  else return inf;
}
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  int n = nums1.size();
  int m = nums2.size();
  if((n + m) & 1)
  {
    int tar = (n + m) / 2;
    int var = BS(nums1,nums2,tar);
    int ans;
    if(var != inf) ans = var;
    else ans = BS(nums2,nums1,tar);
    double final = (double)ans;
    return final;
  }
    else 
  {
      int first,second;
      int tar = (n + m) / 2;
      second = BS(nums1,nums2,tar);
      if(second == inf) second = BS(nums2,nums1,tar);
      first = BS(nums1,nums2,tar-1);
      if(first == inf) first = BS(nums2,nums1,tar-1);
      //cout<<first<<" "<<second<<endl;
    if(n > 0 && m > 0 && 
    nums1[0] == nums1[n-1] && nums2[0] == nums2[n-1] && nums1[0] == nums2[0])
    {
      first = nums1[0];
      second = first;
    }
    double ans = ((first + second) / 2.0);
    return ans;
  }
}
};
