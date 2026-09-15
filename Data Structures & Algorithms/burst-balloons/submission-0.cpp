class Solution {
public:
static const int mx = 330;
vector<vector<int>>dp;
int find(int l,int r,vector<int>&ab)
{
  if(l > r) return 0;
  if(dp[l][r] != -1) return dp[l][r];
  int mx = 0;
  for(int i = l;i<=r;i++)
  {
    int cc = ab[i] * ab[l-1] * ab[r+1];
    int left = find(l,i-1,ab);
    int right = find(i+1,r,ab);
    mx = max(mx,cc + left + right);
  }
  return dp[l][r] = mx;
}
    int maxCoins(vector<int>& nums) {
        dp.assign(mx,vector<int>(mx,-1));
        int n = nums.size();
        vector<int>ab(n+2,1);
        for(int i = 1;i<=n;i++) ab[i] = nums[i-1];
        return find(1,n,ab);
    }
};
