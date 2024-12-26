class Solution {
public:
    void findExpressions(vector<int>& nums,int target,int &count,int index,int currSum)
    {
        if(index==nums.size())
        {
            if(currSum==target)
            {
                count++;
            }
            return;
        }
        findExpressions(nums,target,count,index+1,currSum+nums[index]);
        findExpressions(nums,target,count,index+1,currSum-nums[index]);

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int count=0;
        findExpressions(nums,target,count,0,0);
        return count;
    }
};