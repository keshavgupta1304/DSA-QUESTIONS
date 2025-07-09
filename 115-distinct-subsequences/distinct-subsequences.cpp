class Solution {
public:
    // int recur(int ind1, int ind2, const string& s, const string& t,
    //           vector<vector<int>>& dp) {
    //     if (ind2 == 0)
    //         return 1;
    //     if (ind1 == 0) {
    //         return 0;
    //     }
    //     if (dp[ind1][ind2] != -1)
    //         return dp[ind1][ind2];
    //     int dontTake = recur(ind1 - 1, ind2, s, t, dp);
    //     int take = 0;
    //     if (s[ind1 - 1] == t[ind2 - 1]) {
    //         take = recur(ind1 - 1, ind2 - 1, s, t, dp);
    //     }
    //     return dp[ind1][ind2] = take + dontTake;
    // }
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int ind1 = 0; ind1 <= n1; ind1++) {
            dp[ind1][0] = 1;
        }
        for (int ind1 = 1; ind1 <= n1; ind1++) {
            for (int ind2 = 1; ind2 <= n2; ind2++) {
                long long dontTake = dp[ind1 - 1][ind2];
                long long take = 0;
                if (s[ind1 - 1] == t[ind2 - 1]) {
                    take = dp[ind1 - 1][ind2 - 1];
                }
                dp[ind1][ind2] = (int)take + dontTake;
            }
        }
        return dp[n1][n2];
    }
};