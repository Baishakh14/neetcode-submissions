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

class Solution {
public:
bool canAttendMeetings(vector<Interval>& intervals) {
    vector<pair<int,int>>ab;
    for(auto it : intervals)
    {
        ab.push_back({it.start,it.end});
    }
        sort(ab.begin(),ab.end());
          bool ans = true;
  int val = ab[0].second;
  int n = ab.size();
  for(int i = 1;i<n;i++)
  {
    if(ab[i].first < val) ans = false;
    val = ab[i].second;
  }
  return ans;
    }
};
