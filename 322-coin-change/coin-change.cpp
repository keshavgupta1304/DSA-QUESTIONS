class Solution {
public:
    int recur(int index,int target,const vector<int>& coins,vector<vector<int>>& dp)
    {
        if(index==0)
        {
            if(target%coins[0]==0) return target/coins[0];
            else return 1e9;
        }
        if(dp[index][target]!=-1) return dp[index][target];
        int notTake=0+recur(index-1,target,coins,dp);
        int take=INT_MAX;
        if(coins[index]<=target)
        {
            take=1+recur(index,target-coins[index],coins,dp);
        }
        return dp[index][target]=min(notTake,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        if(amount==0) return 0;
        int ans=recur(n-1,amount,coins,dp);
        return ans>=1e9?-1:ans;
    }
};