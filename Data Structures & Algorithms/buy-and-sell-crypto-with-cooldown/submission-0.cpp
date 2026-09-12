class Solution {
public:
vector<vector<int>>dp;
int find(int ind,int take,vector<int>& prices)
{
  if(ind >= prices.size()) return 0;
  if(dp[ind][take] != -1) return dp[ind][take];
  int now = 0;
  if(take == 0)
  {
    int nici = find(ind + 1,1,prices) - prices[ind];
    int nanici = find(ind + 1,0,prices);
    now = max(nici,nanici);
  }
  else 
  {
    int sell = prices[ind] + find(ind + 2,0,prices);
    int skip = find(ind + 1,1,prices);
    now = max(sell,skip);
  }
  return dp[ind][take] = now;
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n,vector<int>(2,-1));
        return find(0,0,prices);
    }
};
