class Solution {
private:
    int F[30][30][30]; 
    int G[30][30][30]; 

    pair<int, int> dp(int n, int f, int s) {
        if (F[n][f][s]) return {F[n][f][s], G[n][f][s]};

        if (f + s == n + 1) return {1, 1};

        if (f + s > n + 1) {
            auto [ear, lat] = dp(n, n + 1 - s, n + 1 - f);
            F[n][f][s] = ear;
            G[n][f][s] = lat;
            return {ear, lat};
        }

        int minRound = INT_MAX, maxRound = INT_MIN;
        int half = (n + 1) / 2;

        if (s <= half) {
            for (int i = 0; i < f; ++i) {
                for (int j = 0; j < s - f; ++j) {
                    auto [ear, lat] = dp(half, i + 1, i + j + 2);
                    minRound = min(minRound, ear);
                    maxRound = max(maxRound, lat);
                }
            }
        } else {
            int s_prime = n + 1 - s;
            int midExtra = (n - 2 * s_prime + 1) / 2;

            for (int i = 0; i < f; ++i) {
                for (int j = 0; j < s_prime - f; ++j) {
                    auto [ear, lat] = dp(half, i + 1, i + j + midExtra + 2);
                    minRound = min(minRound, ear);
                    maxRound = max(maxRound, lat);
                }
            }
        }

        F[n][f][s] = minRound + 1;
        G[n][f][s] = maxRound + 1;
        return {F[n][f][s], G[n][f][s]};
    }

public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        memset(F, 0, sizeof(F));
        memset(G, 0, sizeof(G));
        if (firstPlayer > secondPlayer) swap(firstPlayer, secondPlayer);

        auto [earliest, latest] = dp(n, firstPlayer, secondPlayer);
        return {earliest, latest};
    }
};