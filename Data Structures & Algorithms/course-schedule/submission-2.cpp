#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
static const int mx = 1e3 + 10;
vector<vector<int>>g;
vector<int>vec;
int vis[mx];
bool dfs(int node)
{
    bool find = false;
    vis[node] = 1;
    vec.push_back(node);
    for(auto it : g[node])
    {
        if(vis[it] == 1) return true;
        if(!vis[it]) find |= dfs(it);
    }
    vis[node] = 2;
    return find;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() == 0) return true;
        g.clear();
        g.resize(mx);
        int f,s;
        for(auto it : prerequisites)
        {
            f = it[0];
            s = it[1];
            g[f].push_back(s);
        }
        memset(vis,0,sizeof(vis));
        for(int i = 0;i<=numCourses;i++)
        {
            if(!vis[i]) 
            {
                if(dfs(i)) return false;
            }
        }
        return true;
    }
};
