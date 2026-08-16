class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
      int n =matrix.size();
      int m = matrix[0].size();
  vector<int>ab;
  for(auto it : matrix)
  {
    for(auto ti : it) ab.push_back(ti);
  }
  auto it = lower_bound(ab.begin(),ab.end(),target);
  if(it != ab.end() && *it == target) return true;
  else return false;
    }
};
