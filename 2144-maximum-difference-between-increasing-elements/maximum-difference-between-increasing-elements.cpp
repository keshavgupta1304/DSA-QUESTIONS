class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int res=-1;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]>nums[i]) res=max(res,nums[j]-nums[i]);
            }
        }
        return res;
    }
};