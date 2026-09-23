/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

bool cmp(Interval &a,Interval &b)
{
    if(a.start != b.start) return a.start > b.start;
    else return a.end > b.end; 
}
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) 
    {
        sort(intervals.begin(),intervals.end(),cmp);
        multiset<int>st;
        for(int i = 0;i<intervals.size();i++)
        {
            int l = intervals[i].start;
            int r = intervals[i].end;
            auto it = st.lower_bound(r);
            if(it == st.end())
            {
                st.insert(l);
            }
            else 
            {
                st.erase(it);
                st.insert(l);
            }
        }
        return st.size();
    }
};
