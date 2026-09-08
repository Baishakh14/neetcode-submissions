class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        map<char,int>ind;
        map<char,vector<char>>fre;
        map<char,int>ache;
        bool ans = true;
        for(auto it : words)
        {
            for(char c : it)
            {
                ache[c] = 0;
            }
        }
        for(int i = 0;i<words.size()-1;i++)
        {
            string f = words[i];
            string s = words[i+1];
            int mle = min(f.size(),s.size());
            if(f.size() > s.size() && (f.substr(0,s.size()) == s))
            {
                ans = false;
                break;
            }
            for(int j = 0;j<mle;j++)
            {
                if(f[j] != s[j])
                {
                    ache[s[j]]++;
                    fre[f[j]].push_back(s[j]);
                    break;
                }
            }
        }
        if(!ans) return "";
        string final = "";
        queue<char>q;
        for(auto it : ache)
        {
            if(it.second == 0) q.push(it.first);
        }
        while(!q.empty())
        {
            char c = q.front();
            final.push_back(c);
            q.pop();
            for(auto it : fre[c])
            {
                ache[it]--;
                if(ache[it] == 0) q.push(it);
            }
        }
        if(final.size() != ache.size()) return "";
        else return final;
    }
};
