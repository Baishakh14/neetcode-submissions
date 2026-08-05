class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>fre;
        vector<pair<int,int>>ab;
        for(auto it : nums) fre[it]++;
        for(auto it : fre)
        {
            ab.push_back({it.second,it.first});
        }
        sort(ab.rbegin(),ab.rend());
        vector<int>ans;
        for(auto it : ab)
        {
            ans.push_back(it.second);
            if(ans.size() == k) break;
        }
        return ans;
    }
};
