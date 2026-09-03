class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,int>vis;
        set<string>st;
        for(auto it : wordList)
        {
            st.insert(it);
        }
        queue<string>q;
        q.push(beginWord);
        vis[beginWord] = 1;
        while(!q.empty())
        {
            auto nam = q.front();
            q.pop();
            for(auto it : wordList)
            {
                if(vis.count(it)) continue;
                int cnt = 0;
                for(int i = 0;i<nam.size();i++)
                {
                    if(nam[i] != it[i]) cnt++;
                }
                if(cnt == 1)
                {
                    vis[it] = vis[nam] + 1;
                    q.push(it);
                }
            }
        }
        if(vis.count(endWord)) return vis[endWord];
        else return 0;
    }
};
