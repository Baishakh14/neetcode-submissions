class Solution {
public:
    int maxArea(vector<int>& ab) {
  int n = ab.size();
  cin>>n;
  vector<int>vec = ab;
  reverse(vec.begin(),vec.end());
  vector<int>sm(n);
  sm[0] = vec[0];
  for(int i = 1;i<n;i++) sm[i] = max(sm[i-1],vec[i]);
  int ans = 0;
  for(int i = 0;i<n;i++)
  {
    int ind = lower_bound(sm.begin(),sm.end(),ab[i]) - sm.begin();
    ans = max(ans,ab[i] * ((n - ind - 1) - i));
  }
  vector<int>pm(n);
  pm[0] = ab[0];
  for(int i = 1;i<n;i++)
  {
    pm[i] = max(pm[i-1],ab[i]);
  }
  for(int i = n-1;i>=0;i--)
  {
    int ind = lower_bound(pm.begin(),pm.end(),ab[i]) - pm.begin();
    ans = max(ans,(i - ind) * ab[i]);
  }
  cout<<ans<<endl;
  return ans;
    }
};
