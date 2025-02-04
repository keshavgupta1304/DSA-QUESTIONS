class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxPossibleSum=nums[0];
        int windowMaxSum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            {
                windowMaxSum+=nums[i];
            }
            else
            {
                windowMaxSum=nums[i];
            }
            maxPossibleSum=max(maxPossibleSum,windowMaxSum);
        }
        return maxPossibleSum;
    }
};