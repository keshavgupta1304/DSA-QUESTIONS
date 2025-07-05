class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[triangle.size()-1].size();
        vector<vector<int>> dp;
        for(int i = 0; i < m; ++i) {
            dp.push_back(vector<int>(triangle[i].size(), -1));
        }
        dp[0][0]=triangle[0][0];
        for(int i=1;i<triangle.size();i++)
        {
            for(int j=0;j<=i;j++)
            {

                int upLeft=1e5;
                int up=1e5;
                if(j-1>=0) upLeft=dp[i-1][j-1];
                if(j<triangle[i-1].size()) up=dp[i-1][j];
                dp[i][j]=min(upLeft,up) + triangle[i][j];
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            mini=min(mini,dp[m-1][i]);
        }
        return mini;
    }
};