class Solution {
public:
#define ll long long
    vector<int> productExceptSelf(vector<int>& nums) {
        map<int,int>fre;
        ll gun = 1;
        vector<int>ans;
        for(auto it : nums)
        {
            if(it == 0)
            {
                fre[it]++;
                continue;
            }
            else gun *= it;
        }
        for(auto it : nums)
        {
            if(it == 0)
            {
                if(fre[it] > 1) ans.push_back(0);
                else ans.push_back(gun);
            }
            else 
            {
                if(fre.count(0)) ans.push_back(0);
                else ans.push_back(gun / it);
            }
        }
        return ans;
    }
};
