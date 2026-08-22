#include<bits/stdc++.h>
using namespace std;
const int mx = 10;
int n;
bool vis[mx];
vector<vector<int>>ans;
vector<int>now;
void find(vector<int>&nums)
{
  if(now.size() == n)
  {
    ans.push_back(now);
    return;
  }
  for(int i = 0;i<n;i++)
  {
    if(!vis[i])
    {
      now.push_back(nums[i]);
      vis[i] = true;
      find(nums);
      now.pop_back();
      vis[i] = false;
    }
  }
}
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();
        now.clear();
        memset(vis,false,sizeof(vis));
        n = nums.size();
        find(nums);
        return ans;
    }
};
