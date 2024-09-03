class Solution {
private:
    bool isValidDivisor(int mid,vector<int>& nums, int threshold)
    {
        long long val=0;
        for(auto num:nums)
        {
            if(num%mid==0) val+=num/mid;
            else val+=(num/mid)+1;
        }
        return val<=threshold;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=INT_MAX;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isValidDivisor(mid,nums,threshold))
            {
                ans=min(ans,mid);
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};