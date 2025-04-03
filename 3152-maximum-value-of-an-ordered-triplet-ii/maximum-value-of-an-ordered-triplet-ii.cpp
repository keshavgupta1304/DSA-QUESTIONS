class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi=0;
        long long maxDiff=0;
        long long result=0;
        for(int k=0;k<nums.size();k++)
        {
            result=max(result,maxDiff*nums[k]);
            maxDiff=max(maxDiff,maxi-nums[k]);
            maxi=max(maxi,(long long)nums[k]);
        }
        return result;
    }
};