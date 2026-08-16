class Solution {
public:
int find(vector<int>&piles,int vag)
{
  int ans = 0;
  for(int i = 0;i<piles.size();i++)
  {
    ans += (piles[i] + vag - 1) / vag;
  }
  return ans;
}
  int minEatingSpeed(vector<int>& piles, int h) {
  int ans = *max_element(piles.begin(),piles.end());
  int l = 1,r = ans;
  while(l <= r)
  {
    int mid = l + (r-l)/2;
    if(find(piles,mid) <= h)
    {
      ans = mid;
      r = mid - 1;
    }
    else l = mid + 1;
  }
  return ans;
}
};
