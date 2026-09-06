class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        set<pair<int, int>> st;
        int n = points.size();
        for (auto it : points) {
            int x = it[0];
            int y = it[1];
            st.insert({x, y});
        }
        int x, y;
        auto it = *st.begin();
        x = it.first;
        y = it.second;
        vector<pair<int, int>> taken;
        taken.push_back({x, y});
        st.erase(st.begin());
        set<pair<int, pair<int, int>>> val;  /// cost,x,y;
        for (auto it : st) {
            int cost = abs(x - it.first) + abs(y - it.second);
            val.insert({cost, {it.first, it.second}});
        }
        int ans = 0;
        while (taken.size() < n) {
            auto itt = *val.begin();
            val.erase(val.begin());
            x = itt.second.first;
            y = itt.second.second;
            if (st.find({x, y}) == st.end()) continue;
            st.erase({x, y});
            taken.push_back({x, y});
            ans += itt.first;
            for (auto it : st) {
                int cost = abs(x - it.first) + abs(y - it.second);
                val.insert({cost, {it.first, it.second}});
            }
        }
        return ans;
    }
};
