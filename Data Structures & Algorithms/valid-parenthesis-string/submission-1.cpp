class Solution {
public:
    bool checkValidString(string s) {
        queue<int>star;
        set<int>stc;
        int cnt = 0;
        for(int i = 0;i<s.size();i++)
        {
            if(s[i] == '*') 
            {
                star.push(i);
                continue;
            }
            if(s[i] == '(') stc.insert(i);
            else 
            {
                if(stc.empty() && star.empty()) return false;
                if(!stc.empty())
                {
                    int val = *stc.rbegin();
                    stc.erase(val);
                }
                else star.pop();
            }
        }
        while(!stc.empty())
        {
            int val = *stc.begin();
            stc.erase(stc.begin());
            bool find = false;
            while(!star.empty())
            {
                int top = star.front();
                star.pop();
                if(top > val)
                {
                    find = true;
                    break;
                }
            }
            if(!find) return false;
        }
        return true;
    }
};
