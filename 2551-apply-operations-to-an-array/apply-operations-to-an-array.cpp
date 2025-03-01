class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int> result;
        int cntZero=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1] && nums[i]!=0)
            {
                nums[i]=2*nums[i];
                nums[i+1]=0;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]) result.push_back(nums[i]);
        }
        while(result.size()<n)
        {
            result.push_back(0);
        }
        return result;
    }
};