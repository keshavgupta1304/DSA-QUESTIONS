class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int total_size = nums.size();
        int n = total_size / 3;
        vector<long long> prefix_min_sums(total_size, -1);
        priority_queue<int> max_pq;
        long long current_sum = 0;

        for (int i = 0; i < total_size; ++i) {
            current_sum += nums[i];
            max_pq.push(nums[i]);
            if (max_pq.size() > n) {
                current_sum -= max_pq.top();
                max_pq.pop();
            }
            if (max_pq.size() == n) {
                prefix_min_sums[i] = current_sum;
            }
        }
        vector<long long> suffix_max_sums(total_size, -1);
        priority_queue<int, vector<int>, greater<int>> min_pq;
        current_sum = 0;

        for (int i = total_size - 1; i >= 0; --i) {
            current_sum += nums[i];
            min_pq.push(nums[i]);
            if (min_pq.size() > n) {
                current_sum -= min_pq.top();
                min_pq.pop();
            }
            if (min_pq.size() == n) {
                suffix_max_sums[i] = current_sum;
            }
        }
        long long min_diff = -1;
        for (int i = n - 1; i < 2 * n; ++i) {
            long long current_diff =
                prefix_min_sums[i] - suffix_max_sums[i + 1];
            if (min_diff == -1 || current_diff < min_diff) {
                min_diff = current_diff;
            }
        }

        return min_diff;
    }
};