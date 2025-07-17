class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int res = 2;
        vector<int> dp(k); 

        for (int j = 0; j < k; ++j) {
            fill(dp.begin(), dp.end(), 0);
            for (int i = 0; i < nums.size(); ++i) {
                int mod = nums[i] % k;
                int pos = (j - mod + k) % k;
                dp[mod] = dp[pos] + 1;
                res = max(res, dp[mod]);
            }
        }
        return res;
    }
};
