class Solution {
public:
    int countBalancedPermutations(string num) {
        const int mod = 1e9 + 7;
        int sum = 0;
        int n = num.size();
        for (auto digit : num) {
            sum += digit - '0';
        }
        if (sum & 1)
            return 0;
        vector<long long> fact(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % mod;
        }
        vector<long long> inv(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            inv[i] = mod - (mod / i) * inv[mod % i] % mod;
        }
        vector<long long> invFact(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            invFact[i] = invFact[i - 1] * inv[i] % mod;
        }

        int halfSum = sum / 2;
        int halflen = n / 2;
        vector<vector<int>> dp(halfSum + 1, vector<int>(halflen + 1));
        dp[0][0] = 1;
        vector<int> digits(10);
        for (char c : num) {
            int d = c - '0';
            digits[d]++;
            for (int i = halfSum; i >= d; i--) {
                for (int j = halflen; j > 0; j--) {
                    dp[i][j] = (dp[i][j] + dp[i - d][j - 1]) % mod;
                }
            }
        }

        long long res = dp[halfSum][halflen];
        res = res * fact[halflen] % mod * fact[n - halflen] % mod;
        for (int d : digits) {
            res = res * invFact[d] % mod;
        }
        return res;
    }
};