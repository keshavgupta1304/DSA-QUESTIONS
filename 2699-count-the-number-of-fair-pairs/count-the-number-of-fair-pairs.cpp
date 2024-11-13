class Solution {
public:
    int searchIndex(vector<int>& nums,int low,int high,int target)
    {
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]>=target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int sum1=searchIndex(nums,i+1,nums.size()-1,lower-nums[i]);
            int sum2=searchIndex(nums,i+1,nums.size()-1,upper+1-nums[i]);
            ans+=(1LL)*(sum2-sum1);
        }
        return ans;
    }
};