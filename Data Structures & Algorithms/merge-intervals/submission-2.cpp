class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int n = intervals.size();
        int i = 0;
        while(i < n)
        {
            int l = intervals[i][0];
            int r = intervals[i][1];
            int j = i + 1;
            while(j < n && r >= intervals[j][0])
            {
                l = min(l,intervals[j][0]);
                r = max(r,intervals[j][1]);
                j++;
            }
            ans.push_back({l,r});
            i = j;
        }
        return ans;
    }
};
