class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        for(int i = 32;i>=0;i--)
        {
            if((1LL << i) & n) ans++;
        }
        return ans;
    }
};
