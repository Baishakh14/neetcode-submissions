class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& st) {
        vector<string>now;
        for(auto it : st)
        {
            string hi = it;
            sort(hi.begin(),hi.end());
            now.push_back(hi);
        }
        map<string,vector<string>>fre;
        for(int i = 0;i<st.size();i++)
        {
            string first = st[i];
            string second = now[i];
            fre[second].push_back(first);
        }
        vector<vector<string>>ans;
        for(auto it : fre)
        {
            vector<string>hi;
            for(auto s : it.second) hi.push_back(s);
            ans.push_back(hi);
        }
        return ans;
    }
};
