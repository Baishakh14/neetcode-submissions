class Solution {
public:
    int trap(vector<int>& ab) {
  int n = ab.size();
  int ans = 0;
  multiset<int,greater<int>>st;
  for(auto it : ab) st.insert(it);
  st.erase(st.find(ab[0]));
  int lmx = ab[0];
  for(int i = 1;i<n-1;i++)
  {
    st.erase(st.find(ab[i]));
    int rmx = *st.begin();
    int now = min(lmx,rmx);
    ans += max(0,now - ab[i]);
    lmx = max(ab[i],lmx);
  }
  return ans;
    }
};
