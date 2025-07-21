class Solution {
public:
    int recur(int i, int j, const vector<int>& nums, vector<vector<int>>& dp) {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int maxCoins = INT_MIN;
        for (int index = i; index <= j; index++) {
            int coins = nums[i - 1] * nums[index] * nums[j + 1] +
                        recur(i, index - 1, nums, dp) +
                        recur(index + 1, j, nums, dp);
            maxCoins = max(maxCoins, coins);
        }
        return dp[i][j] = maxCoins;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return recur(1, n, nums, dp);
    }
};