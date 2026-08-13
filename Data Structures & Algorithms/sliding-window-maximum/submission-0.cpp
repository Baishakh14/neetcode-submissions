class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& ab, int k) {
        int n = ab.size();
  vector<int>ans;
  multiset<int,greater<int>>st;
  for(int i = 0;i<k;i++) st.insert(ab[i]);
  for(int i = k;i<n;i++)
  {
    ans.push_back(*st.begin());
    st.erase(st.find(ab[i-k]));
    st.insert(ab[i]);
  }
  ans.push_back({*st.begin()});
  return ans;
    }
};
