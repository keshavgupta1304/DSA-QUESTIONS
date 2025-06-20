class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];                 
                } else {
                    int fromTop  = (i > 0) ? dp[i - 1][j] : INT_MAX;
                    int fromLeft = (j > 0) ? dp[i][j - 1] : INT_MAX;
                    dp[i][j] = grid[i][j] + min(fromTop, fromLeft);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
