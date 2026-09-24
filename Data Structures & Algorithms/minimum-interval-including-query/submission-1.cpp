class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
     map<int,vector<int>>fre;
     vector<pair<int,int>>ab;
     for(int i = 0;i<queries.size();i++)
     {
        ab.push_back({queries[i],i});
     }
     sort(ab.begin(),ab.end());
     vector<int>ans(queries.size(),-1);
     for(auto it : intervals)
     {
        int l = it[0];
        int r = it[1];
        int len = r - l + 1;
        fre[l].push_back(len);
        fre[r+1].push_back(-len);
     }   
     multiset<int>st;
     int i = 0;
     for(auto it : fre)
     {
        int val = it.first;
        while(i < ans.size() && ab[i].first < val)
        {
            int ind = ab[i].second;
            if(!st.empty()) ans[ind] = *st.begin();
            i++;
        }
        for(auto x : it.second) 
        {
            if(x < 0) st.erase(st.find(-x));
            else st.insert(x);
        }
     }
     return ans;
    }
};
