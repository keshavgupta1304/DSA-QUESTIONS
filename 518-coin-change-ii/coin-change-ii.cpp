class Solution {
public:
    int recur(int index,int target,const vector<int>& coins,vector<vector<int>>& dp)
    {
        if(index==0)
        {
            if(target%coins[index]==0) return 1;
            else return 0;
        }
        if(dp[index][target]!=-1) return dp[index][target];
        int notTake=recur(index-1,target,coins,dp);
        int take=0;
        if(coins[index]<=target)
        {
            take=recur(index,target-coins[index],coins,dp);
        }
        return dp[index][target]=take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return recur(n-1,amount,coins,dp);
    }
};