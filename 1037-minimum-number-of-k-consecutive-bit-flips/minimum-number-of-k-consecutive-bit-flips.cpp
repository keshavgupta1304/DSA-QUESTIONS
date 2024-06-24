class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0;
        vector<int> is_flipped(n, 0);
        int flip_count = 0;

        for (int i = 0; i < n; ++i) {
            // Adjust the flip_count for the sliding window
            if (i >= k) {
                flip_count ^= is_flipped[i - k];
            }

            // If current bit is 0 and flip_count is even, or current bit is 1 and flip_count is odd,
            // we need to flip the current window
            if (nums[i] == flip_count % 2) {
                if (i + k > n) {
                    return -1;
                }
                is_flipped[i] = 1;
                flip_count ^= 1;
                flips += 1;
            }
        }

        return flips;
    }
};