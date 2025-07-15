class Solution {
public:
    int recur(int ind,int canbuy,const vector<int>& prices,int fee,vector<vector<int>>& dp)
    {
        if(ind==prices.size()) return 0;
        if(dp[ind][canbuy]!=-1) return dp[ind][canbuy];
        int profit=0;
        if(canbuy)
        {
            profit=max(-prices[ind]+recur(ind+1,0,prices,fee,dp),recur(ind+1,1,prices,fee,dp));
        }
        else
        {
            profit=max(prices[ind]-fee+recur(ind+1,1,prices,fee,dp),recur(ind+1,0,prices,fee,dp));
        }
        return dp[ind][canbuy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return recur(0,1,prices,fee,dp);
    }
};