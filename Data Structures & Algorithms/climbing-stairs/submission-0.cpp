class Solution {
public:
#define ll long long
    int climbStairs(int n) {
       ll ans[50];
       ans[1] = 1;
       ans[2] = 2;
       for(int i = 3;i<50;i++) 
       ans[i] = ans[i-1] + ans[i-2];
    return ans[n];
    }
};
