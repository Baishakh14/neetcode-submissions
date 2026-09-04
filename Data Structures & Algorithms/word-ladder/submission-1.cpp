class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        map<string,int>fre;
        fre[beginWord] = 1;
        for(auto it : wordList) st.insert(it);
        st.erase(beginWord);
        queue<string>q;
        q.push(beginWord);
        while(!q.empty())
        {
            string hi = q.front();
            q.pop();
            for(int i = 0;i<hi.size();i++)
            {
                string now = hi;
                for(char c = 'a';c<='z';c++)
                {
                   now[i] = c;
                   if(st.count(now))
                   {
                    fre[now] = fre[hi] + 1;
                    st.erase(now);
                    q.push(now);
                   }
                }
            }
        }
        return fre[endWord];
    }
};
