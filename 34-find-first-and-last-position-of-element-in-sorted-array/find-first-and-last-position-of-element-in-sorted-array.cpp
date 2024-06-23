class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftValue = leftMostOccurence(nums,target);
        int rightValue = rightMostOccurence(nums,target);
        vector<int> ans;
        ans.push_back(leftValue);
        ans.push_back(rightValue);
        return ans;
    }

    int leftMostOccurence(vector<int>& nums, int target)
    {
        int start = 0;
        int end = nums.size()-1;
 
        int ans=-1;
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                end=mid-1;
            }
            else if(nums[mid]>target)
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return ans;
    }

    int rightMostOccurence(vector<int>& nums, int target)
    {
        int start = 0;
        int end = nums.size()-1;
        
        int ans=-1;
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                start=mid+1;
            }
            else if(nums[mid]>target)
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
            
        }
        return ans;
    }
};