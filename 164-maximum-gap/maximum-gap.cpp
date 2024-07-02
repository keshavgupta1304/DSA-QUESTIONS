class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2)
        {
            return 0;
        }
        sort(nums.begin(),nums.end());
        int maxDifference=-1;
        for(int i=0;i<nums.size()-1;i++)
        {
            maxDifference=max(maxDifference,nums[i+1]-nums[i]);
        }
        return maxDifference;
    }
};