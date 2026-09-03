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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        g.clear();
        g.resize(mx);
        int f,s;
        int ind[mx];
        for(auto it : prerequisites)
        {
            f = it[0];
            s = it[1];
            g[s].push_back(f);
            ind[f]++;
        }
        memset(vis,0,sizeof(vis));
        bool final = false;
        for(int i = 0;i<=numCourses;i++)
        {
            if(!vis[i]) 
            {
                final |= dfs(i);
            }
        }
        vector<int>ans;
        if(final) return ans;
         queue<int>q;
        for(int i = 0;i<numCourses;i++)
        {
            if(ind[i] == 0)
            {
                ans.push_back(i);
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int val = q.front();
            q.pop();
            for(auto it : g[val])
            {
                ind[it]--;
                if(ind[it] == 0)
                {
                    ans.push_back(it);
                    q.push(it);
                }
            }
        }
        return ans;
    }
};
