class Solution {
public:
    // int recur(int index,int target,const vector<int>& coins,vector<vector<int>>& dp)
    // {
    //     if(index==0)
    //     {
    //         if(target%coins[0]==0) return target/coins[0];
    //         else return 1e9;
    //     }
    //     if(dp[index][target]!=-1) return dp[index][target];
    //     int notTake=0+recur(index-1,target,coins,dp);
    //     int take=INT_MAX;
    //     if(coins[index]<=target)
    //     {
    //         take=1+recur(index,target-coins[index],coins,dp);
    //     }
    //     return dp[index][target]=min(notTake,take);
    // }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        // vector<vector<int>> dp(n,vector<int>(amount+1));
        vector<int> prev(amount+1);
        vector<int> curr(amount+1);
        for(int target=0;target<=amount;target++)
        {
            if(target%coins[0]==0) prev[target]=target/coins[0];
            else prev[target]=1e9;
        }
        for(int index=1;index<n;index++)
        {
            for(int target=0;target<=amount;target++)
            {
                int notTake=prev[target];
                int take=INT_MAX;
                if(coins[index]<=target)
                {
                    take=1+curr[target-coins[index]];
                }
                curr[target]=min(notTake,take);
            }
            prev=curr;
        }
        int ans=prev[amount];
        return ans>=1e9?-1:ans;
    }
};