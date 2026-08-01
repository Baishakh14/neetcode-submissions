class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int ans = 0;
    int val = INT_MAX;
    for(auto x : prices)
    {
        ans = max(ans,x - val);
        val = min(val,x);
    }
    return ans;
    }
};
