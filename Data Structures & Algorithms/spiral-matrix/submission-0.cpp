class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int tot = n * m;
        vector<int>ans;
        int rs = 0,cs = 0;
        int re = matrix.size()-1;
        int ce = matrix[0].size() - 1;
        while(ans.size() < tot)
        {
            if(ans.size() == n * m) break;
          /// left to right;
          for(int i = cs;i<=ce;i++) ans.push_back(matrix[rs][i]);
            if(ans.size() == n * m) break;
          /// up to down
          for(int i = rs + 1;i<=re;i++) ans.push_back(matrix[i][ce]);
            if(ans.size() == n * m) break;
          /// right to left;
          for(int i = ce - 1;i>=cs;i--) ans.push_back(matrix[re][i]);
            if(ans.size() == n * m) break;
          /// down to up;
          for(int i = re-1;i>rs;i--) ans.push_back(matrix[i][cs]);
          cs++,rs++,ce--,re--;
        }
        return ans;
    }
};
