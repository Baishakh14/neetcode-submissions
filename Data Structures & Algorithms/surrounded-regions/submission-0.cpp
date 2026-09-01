class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>>q;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(board[i][j] == 'X') continue;
                if(i == 0 || j == 0 || i == n-1 || j == m-1)
                {
                    q.push({i,j});
                    board[i][j] = 'a';
                }
            }
        }
        vector<pair<int,int>>movement = {{1,0},{-1,0},{0,1},{0,-1}};
        while(q.size() > 0)
        {
            auto xy  = q.front();
            q.pop();
            for(auto it : movement)
            {
                int x = it.first + xy.first;
                int y = it.second + xy.second;
                if(x >= 0 && y >= 0 && x < n && y < m && board[x][y] == 
                   'O')
                {
                    board[x][y] = 'a';
                    q.push({x,y});
                }
            }
        }
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(board[i][j] == 'a') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};
