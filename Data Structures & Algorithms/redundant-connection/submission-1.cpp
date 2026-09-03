static const int mx = 1e3 + 10;
vector<int>parent(mx);
vector<int>sz(mx);
class Solution {
public:
vector<int>ans;
void make()
{
    for(int i = 0;i<mx;i++) parent[i] = i,sz[i] = 1;
}
int find(int x)
{
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
bool dsu(int x,int y)
{
    x = find(x);
    y = find(y);
    if(x == y) return true;
    if(sz[y] > sz[x]) swap(x,y);
    parent[y] = x;
    return false;
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        make();
        for(auto it : edges)
        {
            int x = it[0];
            int y = it[1];
            if(dsu(x,y)) 
            {
                ans.push_back(x);
                ans.push_back(y);
            }
        }
        return ans;
}
};
