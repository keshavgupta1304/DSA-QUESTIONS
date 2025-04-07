class Solution {
private:
    bool generateSubset(int index, vector<int>& nums, int target, int sum,vector<vector<int>>& dp) {
        if (sum == target)
            return true;
        if (index == nums.size() || sum > target)
            return false;
        if (dp[index][sum] != -1)
            return dp[index][sum];
        bool include =
            generateSubset(index + 1, nums, target, sum + nums[index],dp);
        bool exclude = generateSubset(index + 1, nums, target, sum,dp);
        return dp[index][sum]=include || exclude;
    }

public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }
        if (totalSum % 2 != 0)
            return false;

        int target = totalSum / 2;
        vector<vector<int>> dp(nums.size(),vector<int>(target,-1));
        return generateSubset(0, nums, target, 0,dp);
    }
};
