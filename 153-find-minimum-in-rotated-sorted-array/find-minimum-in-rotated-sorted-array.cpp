class Solution {
public:
    int findPivot(vector<int>& nums,int n)
    {
        int left=0;
        int right=n-1;
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]>=nums[0])
            {
                left=mid+1;
            }
            else
            {
                right=mid;
            }
        }
        if(nums[left]>nums[0]) return 0;
        return left;
    }
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int findPivotIndex=findPivot(nums,n);
        return nums[findPivotIndex];
    }
};