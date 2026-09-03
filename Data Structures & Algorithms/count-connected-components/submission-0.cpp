class Solution {
public:
vector<vector<int>>g;
vector<int>vis;
int cnt = 0;
void dfs(int node)
{
    vis[node] = 1;
    for(auto it : g[node])
    {
        if(!vis[it]) dfs(it);
    }

}
    int countComponents(int n, vector<vector<int>>& edges) {
        g.assign(n,vector<int>());
        vis.assign(n,0);
        for(auto it : edges)
        {
            int f = it[0];
            int s = it[1];
            g[f].push_back(s);
            g[s].push_back(f);
        }
        for(int i = 0;i<n;i++)
        {
            if(!vis[i]) 
            {
                cnt++;
                dfs(i);
            }
        }
        return cnt;
    }
};
