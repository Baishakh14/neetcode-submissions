class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int l = 0;
        map<char,int>fre;
        for(int i = 0;i<s.size();i++)
        {
            while(fre.count(s[i]))
            {
                fre[s[l]]--;
                if(fre[s[l]] == 0) fre.erase(s[l]);
                l++;
            }
            ans = max(ans,(i - l + 1));
            fre[s[i]]++;
        }
        return ans;
    }
};
