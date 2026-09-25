class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0;i<n;i++){
            for(int j = i + 1;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]); /// diagonal swap
            }
        }
        for(int i = 0;i<n/2;i++)
        {
            int l = i,r = n - i - 1;
            for(int j = 0;j<n;j++)
            {
                swap(matrix[j][l],matrix[j][r]);
            }
        }
    }
};
