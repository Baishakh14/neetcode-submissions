#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
map<char,string>fre;
vector<string>ans;
string now;
void find(int ind,string &digits)
{
    if(ind == digits.size())
    {
        ans.push_back(now);
        return;
    }
    string s = fre[digits[ind]];
    for(int i = 0;i < s.size();i++)
    {
        now.push_back(s[i]);
        find(ind+1,digits);
        now.pop_back();
    }
}
vector<string> letterCombinations(string digits)
{
fre['2'] = "abc";
fre['3'] = "def";
fre['4'] = "ghi";
fre['5'] = "jkl";
fre['6'] = "mno";
fre['7'] = "pqrs";
fre['8'] = "tuv";
fre['9'] = "wxyz";
if(digits.size() == 0) return ans;
find(0,digits);
return ans;
}
};
