class Solution {
public:
    const int mod=1e9+7;
    int recur(int n,int x,int limit,vector<vector<int>>& dp)
    {
        if(n==0) return 1;
        if(n<0) return 0;
        if(dp[n][limit]!=-1) return dp[n][limit];
        int ways=0;
        for(int num=limit;num>=1;num--)
        {
            if(pow(num,x)>n) continue;
            ways=(ways+recur(n-pow(num,x),x,num-1,dp))%mod;
        }
        return dp[n][limit]=ways%mod;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return recur(n,x,n,dp);
    }
};