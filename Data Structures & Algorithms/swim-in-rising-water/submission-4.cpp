class Solution {
    const int inf = INT_MAX;

   public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = inf;
            }
        }
        set<pair<int, pair<int, int>>> st;
        ans[0][0] = grid[0][0];
        st.insert({grid[0][0], {0, 0}});
        vector<pair<int, int>> movement = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!st.empty()) {
            auto now = *st.begin();
            int cost = now.first;
            int x = now.second.first;
            int y = now.second.second;
            st.erase(st.begin());
            if (ans[x][y] != cost) continue;
            for (auto it : movement) {
                int xx = x + it.first;
                int yy = y + it.second;
                if (xx >= 0 && yy >= 0 && xx < n && yy < n) {
                    int val = max(grid[xx][yy], cost);
                    if (val < ans[xx][yy]) {
                        ans[xx][yy] = val;
                        st.insert({val, {xx, yy}});
                    }
                }
            }
        }
        return ans[n-1][n-1];
    }
};
