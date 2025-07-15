class Solution {
public:
    // int recur(int ind, int canbuy, const vector<int>& prices, int fee,
    //           vector<vector<int>>& dp) {
    //     if (ind == prices.size())
    //         return 0;
    //     if (dp[ind][canbuy] != -1)
    //         return dp[ind][canbuy];
    //     int profit = 0;
    //     if (canbuy) {
    //         profit = max(-prices[ind] + recur(ind + 1, 0, prices, fee, dp),
    //                      recur(ind + 1, 1, prices, fee, dp));
    //     } else {
    //         profit = max(prices[ind] - fee + recur(ind + 1, 1, prices, fee, dp),
    //                      recur(ind + 1, 0, prices, fee, dp));
    //     }
    //     return dp[ind][canbuy] = profit;
    // }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int ahead_not_hold = 0;
        int ahead_hold = 0;
        for (int ind = n - 1; ind >= 0; ind--) {
            int current_not_hold =
                max(prices[ind] - fee + ahead_hold, ahead_not_hold);
            int current_hold = max(-prices[ind] + ahead_not_hold, ahead_hold);

            ahead_not_hold = current_not_hold;
            ahead_hold = current_hold;
        }
        return ahead_hold;
    }
};