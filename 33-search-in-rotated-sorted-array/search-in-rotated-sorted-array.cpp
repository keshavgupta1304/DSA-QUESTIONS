class Solution {
public:
    int findPivot(vector<int>& nums)
    {
        int left=0;
        int right=nums.size()-1;
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]>=nums[0])
            {
                left=mid+1;
            }
            else{
                right=mid;
            }
        }
        return left;
    }

    int binarySearch(vector<int>& nums, int target,int left,int right)
    {
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]<target)
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int pivotElementIndex = findPivot(nums);
       
        if(nums[pivotElementIndex]<=target && target<=nums[nums.size()-1])
        {
            return binarySearch(nums,target,pivotElementIndex,nums.size()-1);
        }
        else
        {
            return binarySearch(nums,target,0,pivotElementIndex-1);
        }
       
    }
};