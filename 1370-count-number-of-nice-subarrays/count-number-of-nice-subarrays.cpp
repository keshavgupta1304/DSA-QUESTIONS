class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_count;
        prefix_count[0] = 1;
        int prefix_sum = 0;
        int result = 0;
        for (int num : nums) {
            // Increment prefix sum by 1 if the number is odd
            if (num & 1) {
                prefix_sum += 1;
            }
            
            // Check if there exists a prefix sum that, when subtracted from current prefix sum, equals k
            if (prefix_count.find(prefix_sum - k) != prefix_count.end()) {
                result += prefix_count[prefix_sum - k];
            }
            
            // Update the count of the current prefix sum 
            if (prefix_count.find(prefix_sum) != prefix_count.end()) {
                prefix_count[prefix_sum] += 1;
            } else {
                prefix_count[prefix_sum] = 1;
            }
        }
        return result;
    }
};