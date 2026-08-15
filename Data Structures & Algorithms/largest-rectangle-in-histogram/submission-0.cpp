#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
const int inf = 1e5;
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
  vector<int>ab(n+2,-inf);
  for(int i = 1;i<=n;i++) ab[i] = heights[i-1];
  vector<int>pse(n+2),nse(n+2); /// next smaller element,previous smaller element
  stack<int>st;
  st.push(0);
  for(int i = 1;i<=n;i++)
  {
    while(ab[i] <= ab[st.top()]) st.pop();
    pse[i] = st.top();
    st.push(i);
  }
  // for(int i = 1;i<=n;i++) cout<<pse[i]<<" ";
  // cout<<endl;
  st = stack<int>();
  st.push(n+1);
  for(int i = n;i>=1;i--)
  {
    while(ab[i] <= ab[st.top()]) st.pop();
    nse[i] = st.top();
    st.push(i);
  }
    // for(int i = 1;i<=n;i++) cout<<nse[i]<<" ";
    // cout<<endl;
  int ans = INT_MIN;
  for(int i = 1;i<=n;i++)
  {
    int l = pse[i];
    int r = nse[i];
    ans = max(ans,(r - l - 1) * ab[i]);
  }
  return ans;
    }
};
