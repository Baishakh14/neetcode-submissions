class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ans = true;
        /// check row;
        for(int i = 0;i<9;i++)
        {
            map<char,int>fre;
            for(int j = 0;j<9;j++)
            {
                if(isdigit(board[i][j])) 
                {
                    if(fre.count(board[i][j])) ans = false;
                    fre[board[i][j]]++;
                }
            }
        }
        /// check colom
        for(int i = 0;i<9;i++)
        {
            map<char,int>fre;
            for(int j = 0;j<9;j++)
            {
                if(isdigit(board[j][i])) 
                {
                    if(fre.count(board[j][i])) ans = false;
                    fre[board[j][i]]++;
                }
            }
        }
        /// check 3,3 sub box
        for(int i = 0;i<9;i+=3)
        {
            for(int j = 0;j<9;j+=3)
            {
                if(i + 3 <= 9 && j + 3 <= 9)
                {
                    map<int,int>fre;
                    for(int k = 0;k<3;k++)
                    {
                        for(int l = 0;l<3;l++)
                        {
                            if(isdigit(board[i+k][j+l]))
                            {
                                int num = board[i+k][j+l] - '0';
                                if(fre.count(num)) ans = false;
                                fre[num]++;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
