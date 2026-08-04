class Solution {
public:
    int reverse(int x) {
        if(x == 0) return 0;
        int ans = 0;
        int X = abs(x);
        while(X)
        {
            int last = X % 10;
            if(ans > (INT_MAX / 10)) return 0;
            ans = (ans * 10) + last;
            X /= 10;
        }
        if(x < 0) return -ans;
        else return ans;
    }
};
