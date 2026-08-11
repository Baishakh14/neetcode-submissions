class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n > m) return false;
        multiset<char>a,b;
        for(auto it : s1) a.insert(it);
        for(int i = 0;i<n;i++) b.insert(s2[i]);
        if(a == b) return true;
        for(int i = n;i<m;i++)
        {
            b.erase(b.find(s2[i-n]));
            b.insert(s2[i]);
            if(a == b) return true;
        }
        return false;
    }
};
