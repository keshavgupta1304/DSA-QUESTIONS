class Solution {
public:
    int bs(const vector<vector<int>>& events, int target) {
        int low = 0;
        int high = events.size() - 1;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (events[mid][0] <= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<int> nextIndex(n);
        for (int i = 0; i < n; ++i) {
            nextIndex[i] = bs(events, events[i][1]);
        }
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int index = n - 1; index >= 0; index--) {
            for (int limit = 1; limit <= k; limit++) {
                int notTake = dp[index + 1][limit];
                int take = events[index][2];
                if (nextIndex[index] != -1)
                    take += dp[nextIndex[index]][limit - 1];
                dp[index][limit] = max(take, notTake);
            }
        }
        return dp[0][k];
    }
};