class Solution {
public:
    // long long recur(int i, int j, const vector<int>& cuts,
    //                 vector<vector<int>>& dp) {
    //     if (i > j)
    //         return 0;
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     long long mini = LLONG_MAX;
    //     for (int index = i; index <= j; index++) {
    //         long long cost = cuts[j + 1] - cuts[i - 1] +
    //                          recur(i, index - 1, cuts, dp) +
    //                          recur(index + 1, j, cuts, dp);
    //         mini = min(mini, cost);
    //     }
    //     return dp[i][j] = mini;
    // }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        int c = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        vector<vector<int>> dp(c + 2, vector<int>(c + 1, 0));
        for (int i = c; i >= 1; i--) {
            for (int j = i; j <= c; j++) {
                int mini = INT_MAX;
                for (int index = i; index <= j; index++) {
                    int cost = cuts[j + 1] - cuts[i - 1] +
                                     dp[i][index - 1] +
                                     dp[index + 1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c];
    }
};