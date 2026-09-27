#include<bits/stdc++.h>
using namespace std;
class CountSquares {
public:
static const int mx = 1000 + 10;
      vector<vector<int>>fre;
    CountSquares() {
        fre.assign(mx,vector<int>(mx,0));
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        fre[x][y]++;
    }
    
    int count(vector<int> point) {
        int cnt = 0;
        int x = point[0];
        int y = point[1];
        ///y upor x bam a count
        for(int i = 1;i<1000;i++)
        {
            int yy = y + i;
            int xx = x - i;
            if(yy > 1000 || xx < 0) break;
            int now = fre[x][yy] * fre[xx][y] * fre[xx][yy];
            cnt += now;
        }
        /// y upor a x dan a count
        for(int i = 1;i<mx;i++)
        {
            int yy = y + i;
            int xx = x + i;
            if(yy > 1000 || xx > 1000) break;
            int now = fre[xx][yy] * fre[x][yy] * fre[xx][y];
            cnt += now;
        }
        /// y nice x bam a 
        for(int i = 1;i<mx;i++)
        {
            int yy = y - i;
            int xx = x - i;
            if(xx < 0 || yy < 0) break;
            int now = fre[xx][yy] * fre[x][yy] * fre[xx][y];
            cnt += now;
        }
        /// y nice x dan a 
        for(int i = 1;i<mx;i++)
        {
            int yy = y - i;
            int xx = x + i;
            if(xx > 1000 || yy < 0) break;
            int now = fre[xx][yy] * fre[x][yy] * fre[xx][y];
            cnt += now;
        }
        return cnt;
    }
};
