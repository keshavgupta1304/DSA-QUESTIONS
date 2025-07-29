class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        vector<int> latest(32, -1);
        for (int i = n - 1; i >= 0; i--) {
            int farthest = i;
            for (int b = 0; b < 32; b++) {
                if (nums[i] & (1 << b)) {
                    latest[b] = i;
                }
                if (latest[b] != -1) {
                    farthest = max(farthest, latest[b]);
                }
            }
            result[i] = farthest - i + 1;
        }

        return result;
    }
};