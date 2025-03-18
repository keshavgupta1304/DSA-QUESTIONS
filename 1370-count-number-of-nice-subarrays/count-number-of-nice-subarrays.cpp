class Solution {
private:
    int noOfSubarraysAtMostKOdd(vector<int>& nums, int k)
    {
        int left=0;
        int n=nums.size();
        int niceSub=0;
        int oddCount=0;
        for(int right=0;right<n;right++)
        {
            if(nums[right]&1) oddCount++;
            while(left<=right && oddCount>k)
            {
                if(nums[left]&1) oddCount--;
                left++;
            }
            niceSub+=right-left+1;
        }
        return niceSub;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return noOfSubarraysAtMostKOdd(nums,k)-noOfSubarraysAtMostKOdd(nums,k-1);
    }
};