class Solution {
public:
vector<string>now;
vector<vector<string>>ans;
static const int mx = 10;
int vis[mx][mx];
void find(int cnt,int n,int x) /// the row, only thing i need;
{
    if(cnt == n)
    {
        ans.push_back(now);
        return;
    }
    for(int i = 0;i<n;i++)
    {
        if(vis[x][i] == 0)
        {
            now[x][i] = 'Q';
            for(int j = 0;j<n;j++)
            {
                vis[x][j] += 1;
                vis[j][i] += 1;
            }
            int r = x,c = i;
            while( r < n && c < n)
            {
                vis[r][c] += 1;
                r++,c++;
            }
            r = x,c = i;
            while(r < n && c >= 0)
            {
                vis[r][c] += 1;
                r+=1,c-=1;
            }
            find(cnt + 1,n,x+1);
            now[x][i] = '.';
            for(int j = 0;j<n;j++)
            {
                vis[x][j] -= 1;
                vis[j][i] -= 1;
            }
            r = x,c = i;
            while( r < n && c < n)
            {
                vis[r][c] -= 1;
                r++,c++;
            }
            r = x,c = i;
            while(r < n && c >= 0)
            {
                vis[r][c] -= 1;
                r+=1,c-=1;
            }
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        for(int i = 0;i<n;i++)
        {
            string hi = "";
            for(int j = 0;j<n;j++) hi.push_back('.'),vis[i][j] = 0;
            now.push_back(hi);
        }
            find(0,n,0);
            return ans;
    }
};
