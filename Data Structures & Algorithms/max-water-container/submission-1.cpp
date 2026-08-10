class Solution {
public:
    int maxArea(vector<int>& ab) {
        int ans = 0;
        int l = 0,r = ab.size() - 1;
        while(l < r)
        {
            ans = max(ans,min(ab[l],ab[r]) * (r - l));
            if(ab[l] < ab[r]) l++;
            else r--;
        }
        return ans;
    }
};
