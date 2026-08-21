class Twitter {
public:
int time = 1;
map<int,set<int>>fkore;
map<int,vector<pair<int,int>>>post; /// person,post,time;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        post[userId].push_back({tweetId,time});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>pq;
        for(auto it : post[userId])
        {
            pq.push({it.second,it.first});
        }
        for(auto it : fkore[userId])
        {
            for(auto ti : post[it])
            {
                pq.push({ti.second,ti.first});
            }
        }
        vector<int>ans;
        while(!pq.empty())
        {
            if(ans.size() == 10) break;
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        fkore[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        fkore[followerId].erase(followeeId);
    }
};
