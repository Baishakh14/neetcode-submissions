class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = speed.size();
  vector<pair<int,int>>ab(n);
  for(int i = 0;i<n;i++) ab[i].first = position[i];
  for(int i = 0;i<n;i++) ab[i].second = speed[i];
  sort(ab.begin(),ab.end(),greater<pair<int,int>>());
  stack<double>st;
  double dis = ((double)target - ab[0].first) / ab[0].second;
  st.push(dis);   
  for(int i = 1;i<n;i++)
  {
    double dis = ((double)target - ab[i].first) / ab[i].second;
    if(dis > st.top()) st.push(dis);
  }
  return st.size();
    }
};
