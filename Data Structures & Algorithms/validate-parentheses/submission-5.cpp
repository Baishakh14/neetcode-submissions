#include<bits/stdc++.h>
class Solution {
public:
bool isfor(char c)
{
    return ((c == '(') || (c == '{') || (c == '['));
}
bool isValid(string &s) 
{
    stack<char>st;
    bool ans = true;
    int n = s.size();
    for(int i = 0;i<n;i++)
    {
        if(isfor(s[i])) st.push(s[i]);
        else 
        {
            if(st.empty()) 
            {
                ans = false;
                break;
            }
            if(s[i] == ')')
            {
                if(st.top() != '(') ans = false;
            }
            else if(s[i] == '}')
            {
                if(st.top() != '{') ans = false;
            }
            else 
            {
                if(st.top() != '[') ans = false;
            }
            if(!ans) break;
            else st.pop();
        }
    }
    return (ans && st.empty());
    }
};
