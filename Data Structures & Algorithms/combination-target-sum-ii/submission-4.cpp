class Solution {
public:
int n;
vector<int>pre;
vector<vector<int>>bai;
vector<int>now;
void find(int ind,vector<int> &candidates,int sum,int target)
{
    if(sum == target)
    {
        bai.push_back(now);
        return;
    }
    if(ind == n) return;
    int baki = (pre[n-1] - pre[ind]);
    if( sum + candidates[ind] + baki < target)
    return;
    if(sum + candidates[ind] > target) return;
    now.push_back(candidates[ind]);
    find(ind + 1,candidates,sum + candidates[ind],target);
    now.pop_back();
    int iind = upper_bound(candidates.begin(),candidates.end(),candidates[ind])
    - candidates.begin();
    find(iind,candidates,sum,target);

}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(),candidates.end());
        n = candidates.size();
        pre.resize(n,0);
        pre[0] = candidates[0];
        for(int i = 1;i<n;i++) pre[i] = pre[i-1] + candidates[i];
        find(0,candidates,0,target);
        // vector<vector<int>>ans;
        // for(auto it : bai)
        // {
        //     vector<int>hi;
        //     for(auto ti : it)
        //     {
        //         hi.push_back(ti);
        //     }
        //     ans.push_back(hi);
        // }
        return bai;
    }
};
