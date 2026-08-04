class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int bit = 31;
        uint32_t ans = 0;
        for(int i = 0;i<=32;i++)
        {
            if((1LL << i) & n)
            {
                ans += (1LL << bit);
            }
            bit--;
        }
        return ans;
    }
};
