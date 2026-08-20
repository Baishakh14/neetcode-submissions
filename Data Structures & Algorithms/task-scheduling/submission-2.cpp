class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
  map<char,int>fre;
  for(char it : tasks) fre[it]++;
  vector<pair<int,char>>ab;
  for(auto it : fre)
  {
    ab.push_back({it.second,it.first});
  }
  sort(ab.rbegin(),ab.rend());
  int sum = 0;
  for(int i = 0;i<ab.size();i++)
  {
    if(i > n) sum += ab[i].first;
  }

  for(int i = 1;i<min(n+1,(int)ab.size());i++)
  {
    int lage = ab[0].first - 1;
    if(ab[i].first < lage)
    {
      int x = (lage - ab[i].first);
      int jabe = min(x,sum);
      ab[i].first += jabe;
      sum -= jabe;
    }
  }
  int ans = tasks.size();
  for(int i = 1;i<min(n + 1,(int)ab.size());i++)
  {
    int lage = ab[0].first - 1;
    ans += max(0,lage - ab[i].first);
  }
  int lage = ab[0].first - 1;
  int sz = ab.size() - 1;
  if(sz < n)
  {
    int baki = (n - sz);
    ans += (lage * baki);
  }
  return ans;
    }
};
