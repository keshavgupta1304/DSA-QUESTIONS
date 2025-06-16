class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount==0) return 1;
        int k = coins.size();
        sort(coins.begin(), coins.end());            
        vector<vector<unsigned long long>> dp(amount + 1, vector<unsigned long long>(k, 0));
        for (int idx = 0; idx < k; ++idx) {
            if (coins[idx] <= amount)
                dp[coins[idx]][idx] = 1;               
        }
        for (int s = 0; s <= amount; ++s) {
            for (int last = 0; last < k; ++last) {
                unsigned long long ways = dp[s][last];
                if (ways == 0) continue;            
                for (int next = last; next < k; ++next) {
                    int newSum = s + coins[next];
                    if (newSum > amount) break;        
                    dp[newSum][next] += ways;
                }
            }
        }
        unsigned long long ans = 0;
        for (int idx = 0; idx < k; ++idx)
            ans += dp[amount][idx];

        return static_cast<int>(ans);
    }
};
