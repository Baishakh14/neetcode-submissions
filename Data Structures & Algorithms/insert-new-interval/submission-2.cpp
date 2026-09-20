class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int i = 0;
        int n = intervals.size();
        while(i < n && newInterval[0] > intervals[i][1])
        {
            ans.push_back(intervals[i]);
            i++;
        }
        int l = newInterval[0];
        int r = newInterval[1];
        while(i < n && newInterval[1] >= intervals[i][0])
        {
            l = min(intervals[i][0],l);
            r = max(r,intervals[i][1]);
            i++;
        }
        ans.push_back({l,r});
        while(i < n) ans.push_back(intervals[i]),i++;
        return ans;
    }
};
