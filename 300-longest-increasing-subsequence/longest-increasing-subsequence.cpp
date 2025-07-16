class Solution {
public:
    // int recur(int ind, int prev_ind, const vector<int>& nums,
    //           vector<vector<int>>& dp) {
    //     if (ind == nums.size())
    //         return 0;
    //     if (dp[ind][prev_ind] != -1)
    //         return dp[ind][prev_ind];
    //     int len = recur(ind + 1, prev_ind, nums, dp);
    //     if (prev_ind == 0 || nums[ind] > nums[prev_ind - 1]) {
    //         len = max(len, 1 + recur(ind + 1, ind + 1, nums, dp));
    //     }
    //     return dp[ind][prev_ind] = len;
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        vector<int> curr(n+1,0);
        vector<int> ahead(n+1,0);
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev_ind = n; prev_ind >= 0; prev_ind--) {
                int len = ahead[prev_ind];
                if (prev_ind == 0 || nums[ind] > nums[prev_ind - 1]) {
                    len = max(len, 1 + ahead[ind + 1]);
                }
                curr[prev_ind] = len;
            }
            ahead=curr;
        }
        return ahead[0];
    }
};