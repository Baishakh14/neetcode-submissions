class Solution {
public:
bool find(map<char,int>&first,map<char,int>&second)
{
  for(auto it : second)
  {
    char c = it.first;
    if(first[c] < it.second) return false;
  }
  return true;
}
string minWindow(string s, string t) {
  int n = s.size();
  int m = t.size();
  map<char,int>fre,check;
  for(auto it : t) check[it]++;
  int l = 0,r = 0;
  int ansl = 0,ansr = -1;
  int len = 0;
  for(;r<n;r++)
  {
    fre[s[r]]++;
    if(find(fre,check)) 
    {
      ansl = 0;
      ansr = r;
      len = r + 1;
      break;
    }
  }
  while(find(fre,check))
    {
      if((r - l + 1) < len)
      {
        len = r - l + 1;
        ansl = l;
        ansr = r;
      }
      fre[s[l]]--;
      if(fre[s[l]] == 0) fre.erase(s[l]);
      l++;
    }
  for(int i = r+1;i<n;i++)
  {
    fre[s[i]]++;
    while(find(fre,check))
    {
      if((i - l + 1) < len)
      {
        len = i - l + 1;
        ansl = l;
        ansr = i;
      }
      fre[s[l]]--;
      if(fre[s[l]] == 0) fre.erase(s[l]);
      l++;
    }
  }
  string final = "";
  for(int i = ansl;i<=ansr;i++) final.push_back(s[i]);
  return final;
    }
};
