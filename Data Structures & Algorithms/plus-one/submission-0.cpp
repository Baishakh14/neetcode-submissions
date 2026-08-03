class Solution {
public:
    vector<int> plusOne(vector<int>& ab) {
        int n = ab.size();
  int hat = 1;
  vector<int>ans;
  for(int i = n-1;i>=0;i--)
  {
    int x = ab[i];
    x += hat;
    hat = 0;
    ans.push_back(x % 10);
    if(x > 9) hat = 1;
  }
  if(hat == 1) ans.push_back(1);
  reverse(ans.begin(),ans.end());
  return ans;
    }
};
