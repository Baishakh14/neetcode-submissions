class Solution {
public:
vector<vector<int>>g;
vector<int>vis;
int cnt = 0;
bool dfs(int node,int parent)
{
    vis[node] = 1;
    cnt++;
    bool ans = false;
    for(auto it : g[node])
    {
        if(vis[it] && it != parent) return true;
        if(!vis[it]) ans |= dfs(it,node);
    }
    return ans;
}
    bool validTree(int n, vector<vector<int>>& edges) {
        g.assign(n,vector<int>());
        vis.assign(n,0);
        for(auto it : edges)
        {
            int f = it[0];
            int s = it[1];
            g[f].push_back(s);
            g[s].push_back(f);
        }
        if(dfs(0,-1)) return false;
        else 
        {
            if(cnt == n) return true;
            else return false;
        }
    }
};
