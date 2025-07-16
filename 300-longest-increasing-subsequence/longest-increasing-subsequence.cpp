class Solution {
public:
    vector<vector<int>> memo;
    int solve(int index, int lastValue_index, const vector<int>& nums) {
        if (index < 0) {
            return 0;
        }
        if (memo[index][lastValue_index] != -1) {
            return memo[index][lastValue_index];
        }
        int exclude = solve(index - 1, lastValue_index, nums);
        int include = 0;
        if (lastValue_index == nums.size() || nums[index] < nums[lastValue_index]) {
            include = 1 + solve(index - 1, index, nums);
        }
        return memo[index][lastValue_index] = max(include, exclude);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        memo.resize(n, vector<int>(n + 1, -1));
        return solve(n - 1, n, nums);
    }
};