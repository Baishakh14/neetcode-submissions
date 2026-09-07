class Solution {
    const int inf = INT_MAX;

   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m = flights.size();
        vector<vector<pair<int, int>>> g(n);
        for (auto it : flights) {
            int a, b, c;
            a = it[0];
            b = it[1];
            c = it[2];
            g[a].push_back({b, c});
        }
        set<pair<int, pair<int, int>>> st;  /// cost,ache,k;
        st.insert({0, {src, 0}});
        vector<int>ans(n,inf);
        ans[src] = 0;
        while (!st.empty()) {
            auto now = *st.begin();
            int cost = now.first;
            int ache = now.second.first;
            int kk = now.second.second;
            st.erase(st.begin());
            for (auto it : g[ache]) {
                int jacce = it.first;
                int ccost = it.second;
                if (jacce == dst) {
                    ans[dst] = min(ans[dst], cost + ccost);
                } else {
                    if (ccost + cost < ans[jacce]) {
    if (kk < k) st.insert({cost + ccost, {jacce, kk + 1}});
                    }
                }
            }
        }
        if(ans[dst] == inf) return -1;
        else return ans[dst];
    }
};
