class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
    int gun = 1;
    set<int,greater<int>>st;
    for(int i = 0;i<n;i++)
    {
      if(nums[i] == 0)
      {
        ans = max(ans,0);
        gun = 1;
        st.clear();
        continue;
      }
      gun *= nums[i];
      ans = max(ans,gun);
      if(gun < 0)
      {
        if(st.size() > 0)
        {
          int now = gun / *st.begin();
          ans = max(ans,now);
        }
        st.insert(gun);
      }
    }
    return ans;
    }
};
