#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
static const int mx = 110;
static const int inf = 1e8;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        set<pair<int,int>>st;
        vector<pair<int,int>>g[mx];
        for(auto it : times)
        {
            int a = it[0];
            int b = it[1];
            int c = it[2];
            g[a].push_back({b,c});
        }
        vector<int>dis(mx,inf);
        dis[k] = 0;
        st.insert({0,k});
        while(!st.empty())
        {
            auto fv = *st.begin(); /// fast val;
            st.erase(st.begin());
            int node = fv.second;
            for(auto it : g[node])
            {
                if(dis[node] + it.second < dis[it.first])
                {
                    dis[it.first] = dis[node] + it.second;
                    st.insert({dis[it.first],it.first});
                }
            }
        }
        bool find = true;
        int ans = 0;
        for(int i = 1;i<=n;i++)
        {
            if(dis[i] == inf)
            {
                return -1;
            }
            ans = max(ans,dis[i]);
        }
        return ans;
    }
};
