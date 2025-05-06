class Solution {
public:
    int dp[5001][51][11];

    int solve(vector<int>& position, vector<int>& ti, int time, int merge,
              int i) {

        if (i >= position.size() - 1) {
            if (merge == 0)
                return 0;
            return 1e8;
        }
        int ans = 1e8;
        if (dp[time][i][merge] != -1)
            return dp[time][i][merge];

        ans = min(ans, solve(position, ti, ti[i + 1], merge, i + 1) +
                           (position[i + 1] - position[i]) * time);

        int curr = ti[i + 1];

        int t = 1;
        for (int j = i + 2; j < ti.size(); j++) {
            if (merge - t >= 0) {
                curr += ti[j];
                ans = min(ans, solve(position, ti, curr, merge - t, j) +
                                   (position[j] - position[i]) * time);
                t++;
            } else
                break;
        }
        return dp[time][i][merge] = ans;
    }
    int minTravelTime(int l, int n, int k, vector<int>& position,
                      vector<int>& time) {
        memset(dp, -1, sizeof(dp));
        return solve(position, time, time[0], k, 0);
    }
};