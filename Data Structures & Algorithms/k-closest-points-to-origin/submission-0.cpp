class Solution {
public:
double dis(int a,int b)
{
  return (double)sqrt((a * a) + (b * b));
}
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
int n = points.size();
priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>>pq;
  for(int i = 0;i<n;i++)
  {
    int a = points[i][0];
    int b = points[i][1];
    pq.push({dis(a,b),{a,b}});
  }
  vector<vector<int>>ans;
  for(int i = 0;i<k;i++)
  {
    auto it = pq.top();
    ans.push_back({it.second.first,it.second.second});
    pq.pop();
  }
  return ans;
    }
};
