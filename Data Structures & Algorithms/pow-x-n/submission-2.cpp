class Solution {
public:
double be(double x,int n)
{
    double ans = 1;
    while(n)
    {
        if(n & 1) ans = ans * x;
        n >>= 1;
        x = x * x;
    }
    return ans;
}
    double myPow(double x, int n) {
        int val = abs(n);
        double ans = be(x,val);
        if(n < 0) return 1 / ans;
        else return ans;
    }
};
