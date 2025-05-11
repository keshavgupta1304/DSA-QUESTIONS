class Solution {
public:
    long long helper(int i, int parent, bool flip, int flipd, int k,
                     vector<vector<int>>& adjList, vector<int>& nums,
                     vector<vector<vector<long long>>>& dp) {

        if (flipd > k) flipd = k;

        if (dp[i][flip][flipd] != LLONG_MIN)
            return dp[i][flip][flipd];

        int sign = flip ? -1 : 1;
        long long res = sign * nums[i];

        for (auto &x : adjList[i]) {
            if (x == parent) continue;
            res += helper(x, i, flip, flipd + 1, k, adjList, nums, dp);
        }

    
        if (flipd ==k) {
            long long flipped = sign * -1 * nums[i];
            for (auto &x : adjList[i]) {
                if (x == parent) continue;
                flipped += helper(x, i, !flip,1 , k, adjList, nums, dp);
            }
            res = max(res, flipped);
        }

        return dp[i][flip][flipd] = res;
    }

    long long subtreeInversionSum(vector<vector<int>>& edges, vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> adjList(n);

        for (auto& x : edges) {
            adjList[x[0]].push_back(x[1]);
            adjList[x[1]].push_back(x[0]);
        }

        vector<vector<vector<long long>>> dp(
            n, vector<vector<long long>>(2, vector<long long>(k + 1, LLONG_MIN)));

        return helper(0, -1, false, k, k, adjList, nums, dp);
    }
};