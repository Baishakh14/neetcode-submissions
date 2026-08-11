class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        for(char i = 'A';i<='Z';i++)
        {
            int nm = 0;
            int l = 0;
            for(int j = 0;j<s.size();j++)
            {
                if(s[j] != i) nm++;
                while(nm > k)
                {
                    if(s[l] != i) nm--;
                    l++;
                }
                ans = max(ans,j - l + 1);
            }
        }
        return ans;
    }
};
