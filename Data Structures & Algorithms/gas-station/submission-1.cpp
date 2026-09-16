#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        ll gs = accumulate(gas.begin(),gas.end(),0LL);
        ll cs = accumulate(cost.begin(),cost.end(),0LL);
        if(cs > gs) return -1;
        vector<int>ab;
        for(int i = 0;i<cost.size();i++)
        {
            ab.push_back(gas[i]-cost[i]);
        }
        ll ans = 0;
        ll sum = 0;
        bool onno = false;
        for(int i = 0;i<cost.size();i++)
        {
            sum = max((ll)ab[i],sum + ab[i]);
            if(sum < 0) onno = true;
            if(onno && sum > 0) ans = i,onno = false;
        }
        return ans;
    }
};
