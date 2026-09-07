class Solution {
    const int inf = INT_MAX;

   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>ans(n,inf);
        ans[src] = 0;
        for(int i = 0;i<=k;i++)
        {
            vector<int>now = ans;
            for(auto it : flights)
            {
                int a = it[0];
                int b = it[1];
                int c = it[2];
                if(ans[a] != inf && ans[a] + c < now[b])
                {
                    now[b] = ans[a] + c; /// temp er b update korbo naile onnoe ekta path extra khulbe ba kicu jhamela must hobe
                }
            }
            ans = now;
        }
        if(ans[dst] == inf) return -1;
        else return ans[dst];
    }
};
