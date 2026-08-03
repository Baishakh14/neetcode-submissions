#include<bits/stdc++.h>
class Solution {
public:
    bool isHappy(int n) {
    map<int,int>fre;
    fre[n] = 1;
    bool ans = false;
  if(n == 1) return true;
  while(true)
  {
    string s = to_string(n);
    int num = 0;
    for(auto it : s)
    {
      int val = it - '0';
      num += (val * val);
    }
    n = num;
    if(num == 1) 
    {
      ans = true;
      break;
    }
    if(fre.count(num))
    {
      break;
    }
    fre[num] = 1;
  }
  return ans;
    }
};
