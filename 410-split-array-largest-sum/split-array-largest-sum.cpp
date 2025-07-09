class Solution {
public:
    int recur(int index, int k, const vector<int>& nums,
              vector<vector<int>>& dp) {
        if (k == 1) {
            int s = 0;
            for (int i = 0; i <= index; i++)
                s += nums[i];
            return s;
        }
        if (index + 1 < k)
            return INT_MAX;
        if (dp[index][k] != -1)
            return dp[index][k];
        int ans = INT_MAX;

        int rightSum = 0;
        for (int j = index; j >= k - 1; j--) {
            rightSum += nums[j];
            int left = recur(j - 1, k - 1, nums, dp);
            if (left != INT_MAX)
                ans = min(ans, max(left, rightSum));
        }
        return dp[index][k] = ans;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return recur(n - 1, k, nums, dp);
    }
};