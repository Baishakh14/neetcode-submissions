class Solution {
   public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = intervals.size();
        int m = queries.size();
        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            int x = queries[i];
            q.push_back({x, i});
        }
    sort(q.begin(),q.end());
    vector<int>ans(m,-1);
    int j = 0;
    for(int i = 0;i<m;i++)
    {
      int val = q[i].first;
      int ind = q[i].second;
      while(j < n && intervals[j][0] <= val)
      {
        pq.push({intervals[j][1] - intervals[j][0] + 1,intervals[j][1]});
        j++;
      }
      while(!pq.empty() && pq.top().second < q[i].first) pq.pop();
      if(!pq.empty()) ans[ind] = pq.top().first;
    }
    return ans;
    }
};
