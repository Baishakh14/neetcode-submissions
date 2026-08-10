class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<pair<int,int>>ab;
        set<pair<int,pair<int,int>>>ans;
        for(int i = 0;i<nums.size();i++)
        {
            ab.push_back({nums[i],i});
        }
        sort(ab.begin(),ab.end());
        for(int i = 0;i<ab.size();i++)
        {
            int l = i+1,r = ab.size()-1;
            int lage = (0 - ab[i].first);
            while(l < r)
            {
                int sum = (ab[l].first + ab[r].first);
                if(sum == lage)
                {
ans.insert({ab[i].first,{ab[r].first,ab[l].first}});
l++,r--;
continue;
                }
                if(sum > lage) r--;
                else l++;
            }
        }
        vector<vector<int>>result;
        for(auto it : ans)
        {
            vector<int>hi;
            hi.push_back(it.first);
            hi.push_back(it.second.first);
            hi.push_back(it.second.second);
            result.push_back(hi);
        }
        return result;
    }
};
