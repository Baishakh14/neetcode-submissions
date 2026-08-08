class Solution {
public:
    vector<int> twoSum(vector<int>& ab, int target) {
        map<int,int>fre;
        for(int i = 0;i<ab.size();i++)
        {
            int need = target - ab[i];
            if(fre.count(need))
            {
                return {fre[need],i+1};
            }
            fre[ab[i]] = i + 1;
        }
    }
};
