class Solution {
public:
    const int m = 1e9 + 7;
    long long power(long long base, long long exp) {
        long long res = 1;
        while (exp) {
            if (exp & 1)
                res = (res * base) % m;
            base = (base * base) % m;
            exp = exp >> 1;
        }
        return res;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> powers;
        for (int i = 0; i < 32; i++) {
            if ((n >> i) & 1) {
                powers.push_back(1 << i);
                // n=n-1<<i;
            }
        }
        int sz = powers.size();
        vector<long long> prefix(sz);
        prefix[0] = powers[0];
        for (int i = 1; i < sz; i++) {
            prefix[i] = (powers[i] % m * prefix[i - 1] % m) % m;
        }
        vector<int> answer;
        for (auto& query : queries) {
            int l = query[0];
            int r = query[1];
            answer.push_back(
                (prefix[r] * power((l - 1 >= 0 ? prefix[l - 1] : 1), m - 2)) %
                m);
        }
        return answer;
    }
};