class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<uint> dp(amount+1);
        dp[0]=1;
        for(auto coin:coins)
        {
            for(int s=coin;s<=amount;s++)
            {
                dp[s]+=dp[s-coin];
            }
        }
        return dp[amount];
    }
};