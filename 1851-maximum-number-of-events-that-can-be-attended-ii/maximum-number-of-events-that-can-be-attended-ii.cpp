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
    int recur(int index, int limit, const vector<vector<int>>& events,
              vector<vector<int>>& dp) {
        if (limit == 0)
            return 0;
        if (index == events.size()) {
            return 0;
        }
        if (dp[index][limit] != -1)
            return dp[index][limit];
        int notTake = recur(index + 1, limit, events, dp);

        int nextIndexToTake = bs(events, events[index][1]);
        int take = events[index][2];
        if (nextIndexToTake != -1) {
            take += recur(nextIndexToTake, limit - 1, events, dp);
        }
        return dp[index][limit] = max(take, notTake);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return recur(0, k, events, dp);
    }
};