class Solution {
public:
    int recur(int i,int j,const vector<vector<int>>& triangle,vector<vector<int>>& dp)
    {
        if(i==0 && j==0) return triangle[i][j];
        if(i<0 || j<0 || j>=triangle[i].size()) return 1e5;
        if(dp[i][j]!=-1) return dp[i][j];
        int upLeft=recur(i-1,j-1,triangle,dp);
        int up=recur(i-1,j,triangle,dp);
        return dp[i][j]=triangle[i][j]+min(upLeft,up);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[triangle.size()-1].size();
        vector<vector<int>> dp;
        for(int i = 0; i < m; ++i) {
            dp.push_back(vector<int>(triangle[i].size(), -1));
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            mini=min(mini,recur(triangle.size()-1,i,triangle,dp));
        }
        return mini;
    }
};