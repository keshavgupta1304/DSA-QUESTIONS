class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<uint> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=amount;i++)
        {
            for(auto coin:coins)
            {
                if(i>=coin) dp[i]=min(dp[i],dp[i-coin]+1);
            }
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};