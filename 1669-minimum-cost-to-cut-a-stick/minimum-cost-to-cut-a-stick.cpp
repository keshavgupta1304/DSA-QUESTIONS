class Solution {
public:
    long long recur(int i,int j,const vector<int>& cuts,vector<vector<int>>& dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        long long mini=LLONG_MAX;
        for(int index=i;index<=j;index++)
        {
            long long cost=cuts[j+1]-cuts[i-1] + recur(i,index-1,cuts,dp)+recur(index+1,j,cuts,dp);
            mini=min(mini,cost);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        int c=cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
        return recur(1,c,cuts,dp);
    }
};