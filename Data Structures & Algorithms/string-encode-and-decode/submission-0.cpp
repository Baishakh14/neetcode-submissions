class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(auto it : strs)
        {
            int len = it.size();
            string hi;
            hi += to_string(len);
            hi.push_back('#');
            hi += it;
            ans += hi;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int num = 0;
        for(int i = 0;i<s.size();i++)
        {
            if(s[i] == '#')
            {
                string now = s.substr(i+1,num);
                i = i + num;
                num = 0;
                ans.push_back(now);
                continue;
            }
            num = (num * 10) + (s[i] - '0');
        }
        return ans;
    }
};
