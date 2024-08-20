class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int noOfPiles = piles.size();
        vector<vector<int>> dp(noOfPiles + 1, vector<int>(noOfPiles+1, 0));

        vector<int> suffixSum(noOfPiles + 1, 0);
        for (int i = noOfPiles - 1; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        for (int i = 0; i <= noOfPiles; i++) {
            dp[i][noOfPiles] = suffixSum[i];
        }
        for (int index = noOfPiles - 1; index >= 0; index--) {
            for (int maxTillNow = noOfPiles - 1; maxTillNow >= 1; maxTillNow--) {
                for (int X = 1; X <= 2 * maxTillNow && index + X <= noOfPiles;
                     X++) {
                    dp[index][maxTillNow] = max(
                        dp[index][maxTillNow],
                        suffixSum[index] - dp[index + X][max(maxTillNow, X)]);
                }
            }
        }
        return dp[0][1];
    }
};