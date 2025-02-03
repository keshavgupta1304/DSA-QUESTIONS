class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int lengthOfIncreasing=1;
        int windowIncrease=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            {
                windowIncrease++;
            }
            else
            {
                windowIncrease=1;
            }
            lengthOfIncreasing=max(lengthOfIncreasing,windowIncrease);
        }
        int lengthOfDecreasing=1;
        int windowDecrease=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1])
            {
                windowDecrease++;
            }
            else
            {
                windowDecrease=1;
            }
            lengthOfDecreasing=max(lengthOfDecreasing,windowDecrease);
        }        
        return max(lengthOfDecreasing,lengthOfIncreasing);
    }
};