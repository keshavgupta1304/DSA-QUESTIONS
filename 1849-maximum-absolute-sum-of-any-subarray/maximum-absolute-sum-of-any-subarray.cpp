class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxPrefixSum=0;
        int minPrefixSum=0;
        int prefixSum=0;
        for(int i=0;i<nums.size();i++)
        {
            prefixSum+=nums[i];
            maxPrefixSum=max(maxPrefixSum,prefixSum);
            minPrefixSum=min(minPrefixSum,prefixSum);
        }
        return maxPrefixSum-minPrefixSum;
    }
};