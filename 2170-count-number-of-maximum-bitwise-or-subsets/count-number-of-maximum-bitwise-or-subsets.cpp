class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr=0;
        for(int i=0;i<nums.size();i++)
        {
            maxOr=maxOr|nums[i];
        }
        int subsets=getSubsets(nums,maxOr,0,0);
        return subsets;
    }
    int getSubsets(vector<int>& nums,int maxOr,int index,int currentOr)
    {
        if(index == nums.size())
        {
            return currentOr==maxOr?1:0;
        }
        int countSubsetExcluding=getSubsets(nums,maxOr,index+1,currentOr);
        int countSubsetIncluding=getSubsets(nums,maxOr,index+1,currentOr|nums[index]);

        return countSubsetExcluding+countSubsetIncluding;
    }
};