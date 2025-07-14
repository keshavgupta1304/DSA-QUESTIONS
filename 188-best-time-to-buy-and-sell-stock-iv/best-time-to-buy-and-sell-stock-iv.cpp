class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(
        //     n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        vector<vector<int>> next(2, vector<int>(k+1, 0));
        vector<vector<int>> curr(2, vector<int>(k+1, 0));
        for (int index = n - 1; index >= 0; index--) {
            for (int canBuy = 0; canBuy <= 1; canBuy++) {
                for (int maxTransactions = 0; maxTransactions <= k;
                     maxTransactions++) {
                    int profit = 0;
                    if (canBuy == 1 && maxTransactions == 0)
                        curr[canBuy][maxTransactions] = 0;
                    else {
                        if (canBuy) {
                            profit = max(-prices[index] +
                                             next[0][maxTransactions - 1],
                                         next[1][maxTransactions]);
                        } else {
                            profit =
                                max(prices[index] + next[1][maxTransactions],
                                    next[0][maxTransactions]);
                        }
                        curr[canBuy][maxTransactions] = profit;
                    }
                }
            }
            next = curr;
        }
        return next[1][k];
    }
};