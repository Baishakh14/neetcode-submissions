#include<bits/stdc++.h>
using namespace std;
map<string,multiset<string>>fre;
vector<string>ans;
class Solution {
public:
void dfs(string now,vector<vector<string>>& tickets)
{
  multiset<string>ms = fre[now];
  while(fre[now].size() > 0)
  {
    string ekhn = *fre[now].begin();
    fre[now].erase(fre[now].find(ekhn));
    dfs(ekhn,tickets);
  }
  ans.push_back(now);
}
    vector<string> findItinerary(vector<vector<string>>& tickets) {
    ans.clear();
    fre.clear();
    for(auto it : tickets)
    {
        string a = it[0];
        string b = it[1];
        fre[a].insert(b);
    }
        dfs("JFK",tickets);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
