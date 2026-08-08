class Solution {
public:
    vector<int> twoSum(vector<int>& ab, int target) {
        int l = 0,r = ab.size() - 1;
        while(l < r)
        {
            int sum = ab[l] + ab[r];
            if(sum == target) return {l+1,r+1};
            if(sum > target) r--;
            else l++;
        }
    }
};
