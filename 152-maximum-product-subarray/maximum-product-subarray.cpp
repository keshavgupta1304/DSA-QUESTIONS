class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int n = nums.size();
        int prefix = 1;
        int suffix = 1;
        for (int left = 0; left < n; left++) {
            prefix = prefix * nums[left];
            suffix = suffix * nums[n - left - 1];
            maxi = max(max(prefix, suffix), maxi);
            if (prefix == 0)
                prefix = 1;
            if (suffix == 0)
                suffix = 1;
        }
        return maxi;
    }
};