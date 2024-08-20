class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int index;
        for(index=n-2;index>=0;index--)
        {
            if(nums[index]<nums[index+1])
            {
                break;
            }
        }
        if(index<0)
        {
            reverse(nums.begin(),nums.end());
            return;
        } 
        int ele=INT_MAX;
        int indexOfEle=-1;
        for(int i=index+1;i<n;i++)
        {
            if(nums[i]>nums[index] && nums[i]<ele)
            {
                indexOfEle=i;
                ele=nums[i];
            }
        }
        swap(nums[index],nums[indexOfEle]);
        sort(nums.begin()+index+1,nums.end());
    }
};