class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int f = nums[0]; /// fast 
        int s = nums[0]; /// slow
        do
        {
            f = nums[nums[f]];
            s = nums[s];
        }
        while(f != s);
        s = nums[0];
        while(s != f)
        {
            s = nums[s];
            f = nums[f];
        }
        return s;
    }
};
