class Solution {
public:
    int longestConsecutive(vector<int>& ab) {
    int n = ab.size();
    unordered_map<int,int>fre;
    unordered_set<int>st;
    for(auto it : ab) st.insert(it);
    int ans = 0;
    for(int i = 0;i<n;i++)
    {
        if(fre.count(ab[i])) continue;
        else 
        {
            int now = 1;
            int val = ab[i] + 1;
            while(true)
            {
                if(fre.count(val))
                {
                    now += fre[val];
                    break;
                } 
                if(st.count(val))
                {
                    now++;
                    fre[val] = 0;
                    val += 1;
                }
                else break;
            }
            fre[ab[i]] = now;
            ans = max(ans,now);
        }
    }
    return ans;
    }
};
