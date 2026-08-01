class Solution {
public:
    bool hasDuplicate(vector<int>& ab) {
        map<int,int>fre;
        bool ans = false;
        for(auto it : ab){
            fre[it]++;
            if(fre[it] > 1) ans = true;
        }
        return ans;
    }
};