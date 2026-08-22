class Solution {
public:
vector<vector<int>>ans;
vector<int>now;
int n;
void find(int ind,vector<int> &candidates,int sum,int target)
{
    if(sum == target)
    {
        ans.push_back(now);
        return;
    }
    if(sum > target || ind == n) return;
    for(int i = ind;i<n;i++)
    {
        if(i > ind && candidates[i] == candidates[i - 1]) continue;
        now.push_back(candidates[i]);
        find(i + 1,candidates,sum + candidates[i],target);
        now.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      n = candidates.size();
      sort(candidates.begin(),candidates.end());
      find(0,candidates,0,target);
      return ans;
    }
};
