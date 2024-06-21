class Solution {
public:
    int minimumSum(vector<int>& nums) {
       int sum=0,ans=INT_MAX; 
       for(int i=0;i<nums.size();i++)
       {
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[i]<nums[j])
            {
                for(int k=j+1;k<nums.size();k++)
                {
                    if(nums[k] < nums[j])
                    {
                        sum=nums[i]+nums[j]+nums[k];
                        ans=min(ans,sum);
                    }
                }
            }
        }
       }
       return sum==0?-1:ans;
    
    }
};