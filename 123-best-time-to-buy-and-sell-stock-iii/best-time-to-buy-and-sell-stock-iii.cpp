class Solution {
public:
    // int recur(int index, int canBuy, int maxTransactions,
    //           const vector<int>& prices, vector<vector<vector<int>>>& dp) {
    //     if ((maxTransactions == 0 && canBuy == 1) || (index == prices.size()))
    //         return 0;
    //     int profit = 0;
    //     if (dp[index][canBuy][maxTransactions] != -1)
    //         return dp[index][canBuy][maxTransactions];
    //     if (canBuy) {
    //         profit =
    //             max(-prices[index] +
    //                     recur(index + 1, 0, maxTransactions - 1, prices, dp),
    //                 recur(index + 1, 1, maxTransactions, prices, dp));
    //     } else {
    //         profit = max(prices[index] +
    //                          recur(index + 1, 1, maxTransactions, prices, dp),
    //                      recur(index + 1, 0, maxTransactions, prices, dp));
    //     }
    //     return dp[index][canBuy][maxTransactions] = profit;
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int index = n - 1; index >= 0; index--) {
            for (int canBuy = 0; canBuy <= 1; canBuy++) {
                for (int maxTransactions = 0; maxTransactions <= 2;
                     maxTransactions++) {
                    int profit = 0;
                    if (canBuy == 1 && maxTransactions == 0)
                        dp[index][canBuy][maxTransactions] = 0;
                    else {
                        if (canBuy) {
                            profit =
                                max(-prices[index] + dp[index + 1][0]
                                                           [maxTransactions - 1],
                                    dp[index + 1][1][maxTransactions]);
                        } else {
                            profit = max(prices[index] + dp[index + 1][1]
                                                               [maxTransactions],
                                         dp[index + 1][0][maxTransactions]);
                        }
                        dp[index][canBuy][maxTransactions] = profit;
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};