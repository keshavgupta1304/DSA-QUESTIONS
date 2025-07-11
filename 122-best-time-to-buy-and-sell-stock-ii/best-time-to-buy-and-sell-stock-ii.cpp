class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int aheadNotBuy = 0;
        int aheadBuy = 0;
        int curBuy, curNotBuy;
        for (int ind = n - 1; ind >= 0; ind--) {
            curNotBuy = max(prices[ind] + aheadBuy, aheadNotBuy);
            curBuy = max(-prices[ind] + aheadNotBuy, aheadBuy);
            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy;
        }
        return aheadBuy;
    }
};