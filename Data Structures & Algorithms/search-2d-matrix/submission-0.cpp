class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
  bool find = false;
  int row = -1;
  int l = 0,r = n-1;
  while(l <= r)
  {
    int mid = (l + r) / 2;
    int left = matrix[mid][0];
    int right = matrix[mid][m-1];
    if(target >= left && target <= right)
    {
      row = mid;
      break;
    }
    if(target > right) l = mid + 1;
    else r = mid - 1;
  }
  if(row == -1) 
  {
    return false;
  }
  l = 0,r = m-1;
  while(l <= r)
  {
    int mid = (l + r) / 2;
    if(matrix[row][mid] == target)
    {
      find = true;
      break;
    }
    if(matrix[row][mid] > target) r = mid - 1;
    else l = mid + 1;
  }
  return find;
    }
};
