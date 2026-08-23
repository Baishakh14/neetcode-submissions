class Solution {
public:
vector<vector<string>>ans;
vector<string>now;
bool check(string &s)
{
    int n = s.size();
    for(int i = 0;i<n/2;i++)
    {
        if(s[i] != s[n-i-1]) return false;
    }
    return true;
}
void find(int ind,string &s)
{
    if(ind == s.size())
    {
        ans.push_back(now);
        return;
    }
    string hi = "";
    for(int i = ind;i<s.size();i++)
    {
        hi.push_back(s[i]);
        if(check(hi))
        {
            now.push_back(hi);
            find(i + 1,s);
            now.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        find(0,s);
        return ans;
    }
};
