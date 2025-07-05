class Solution {
public:
    int recur(int i,int j,const vector<vector<int>>& matrix,vector<vector<int>>& dp)
    {
        if(j<0 || j>=matrix.size()) return INT_MAX;
        if(i==matrix.size()-1) return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int belowLeft=recur(i+1,j-1,matrix,dp);
        int belowRight=recur(i+1,j+1,matrix,dp);
        int below=recur(i+1,j,matrix,dp);
        return dp[i][j]=matrix[i][j]+min({belowLeft,belowRight,below});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int mini=INT_MAX;
        vector<int> prev(n);
        for(int i=0;i<n;i++)
        {
            prev[i]=matrix[n-1][i];
        }
        for(int i=n-2;i>=0;i--)
        {
            vector<int> temp(n);
            for(int j=n-1;j>=0;j--)
            {
                int belowRight=j+1>=n?INT_MAX:prev[j+1];
                int belowLeft=j<1?INT_MAX:prev[j-1];
                int below=prev[j];
                temp[j]=matrix[i][j]+min({belowRight,belowLeft,below});
            }
            prev=temp;
        }
        for(int i=0;i<n;i++)
        {
            mini=min(mini,prev[i]);
        }
        return mini;
    }
};