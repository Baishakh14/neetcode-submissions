class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.rbegin(),intervals.rend());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i = 1;i<intervals.size();i++)
        {
            int r = intervals[i][1];
            auto it = ans.back();
            if(r <= it[0])
            {
                ans.push_back(intervals[i]);
            }
        }
        return intervals.size() - ans.size();
    }
};
