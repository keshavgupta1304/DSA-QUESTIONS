class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, 0);
        dp[0] = 1;
        int mod = 1'000'000'007;
        for (int end = 1; end <= high; ++end) {
            if (end >= zero) {
                dp[end] = (dp[end] + dp[end - zero]) % mod;
            }
            if (end >= one) {
                dp[end] = (dp[end] + dp[end - one]) % mod;
            }
        }
        int answer = 0;
        for (int i = low; i <= high; ++i) {
            answer = (answer + dp[i]) % mod;
        }

        return answer;
    }
};
