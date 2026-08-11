class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        for(int i = 0;i<s.size();i++)
        {
            bool fre[200] = {false};
            int len = 0;
            for(int j = i;j<s.size();j++)
            {
                int num = (int)s[j];
                if(fre[num]) break;
                fre[num] = true;
                len++;
            }
            ans = max(ans,len);
        }
        return ans;
    }
};
