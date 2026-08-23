class Solution {
public:
vector<string>ans;
string now;
void find(int n,int open,int close)
{
    if(close > open) return;
    if(now.size() == 2*n)
    {
        ans.push_back(now);
        return;
    }
    if(open < n)
    {
        now.push_back('(');
        find(n,open + 1,close);
        now.pop_back();
    }
    if(close < n)
    {
        now.push_back(')');
        find(n,open,close + 1);
        now.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        find(n,0,0);
        return ans;
    }
};
