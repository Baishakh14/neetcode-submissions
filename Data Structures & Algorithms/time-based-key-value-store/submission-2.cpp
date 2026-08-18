#include<bits/stdc++.h>
using namespace std;
class TimeMap {
public:
map<string,set<pair<int,string>>>fre;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
      fre[key].insert({timestamp,value});
    }
    
    string get(string key, int timestamp) {
      if(!fre.count(key)) return "";
      else 
      {
        auto &bai = fre[key];
        auto it = bai.upper_bound({timestamp,"zzzzzzzzzzz"});
        if(it == bai.begin()) return "";
        else 
        {
        it--;
        return it->second;
        }
      }
    }
};
