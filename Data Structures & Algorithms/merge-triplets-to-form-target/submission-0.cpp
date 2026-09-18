class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int>ans;
        ans.push_back(0);
        ans.push_back(0);
        ans.push_back(0);
        for(auto it : triplets)
        {
            bool ok = true;
            for(int i = 0;i<3;i++)
            {
                if(it[i] > target[i]) ok = false;
            }
            if(!ok) continue;
            for(int i = 0;i<3;i++)
            {
                ans[i] = max(ans[i],it[i]);
            }
        }
        return ans == target;
    }
};
