class Solution {
private:
    int search(vector<int> nums,int element)
    {
        int low=0;
        int high=nums.size()-1;
        int index=nums.size();
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]>=element)
            {
                index=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return index;
    }
    vector<int> listOfIncreasingSubsequence(vector<int> nums)
    {
        vector<int> ans(nums.size(),1);
        vector<int> longestIncSub = {nums[0]};
        for(int i=1;i<nums.size();i++)
        {
            //find index of element in longestIncSub that is greater than or equal to this element
            int index=search(longestIncSub,nums[i]);
            if(index==longestIncSub.size())
            {
                longestIncSub.push_back(nums[i]);
            }
            else
            {
                longestIncSub[index]=nums[i];
            }
            ans[i]=longestIncSub.size();
        }
        return ans;
    }
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int> lenOfIncreasingSub=listOfIncreasingSubsequence(nums);
        reverse(nums.begin(),nums.end());
        vector<int> lenOfDecreasingSub=listOfIncreasingSubsequence(nums);
        reverse(lenOfDecreasingSub.begin(),lenOfDecreasingSub.end());
        int ans=INT_MAX;
        for(int i=1;i<n-1;i++)
        {
            if(lenOfIncreasingSub[i]>1 && lenOfDecreasingSub[i]>1)
            {
                ans=min(ans,(i+1-lenOfIncreasingSub[i])+(n-i-lenOfDecreasingSub[i]));
            }
        }
        return ans;
    }
};