#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<double,int>, null_type, less<pair<double,int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;
class MedianFinder {
public:
pbds ab;
int i = 1;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        ab.insert({num,i});
        i++;
    }
    
    double findMedian() {
        if(ab.size() & 1)
      {
        int ind = (int)ab.size() / 2;
        auto it  = ab.find_by_order(ind);
        double val = (*it).first;
        return val;
      }
      else 
      {
        int ind = (int)ab.size() / 2;
        auto it  = ab.find_by_order(ind);
        double first = (*it).first;
        it--;
        double second = (*it).first;
        double val = (first + second) / 2;
        return val;
      }
    }
};
