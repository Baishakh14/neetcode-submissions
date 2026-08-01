#include<bits/stdc++.h>
class Solution {
public:
bool isPalindrome(string s) {
        string t;
        for(char &it : s)
        {
            if(isalnum(it)) 
            {
                if(isalpha(it)) it = tolower(it);
                t.push_back(it);
            }
        }
        string bai = t;
        reverse(bai.begin(),bai.end());
        return bai == t;
    }
};
