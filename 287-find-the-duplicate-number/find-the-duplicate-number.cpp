class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //binary search
        int left =1; //smallest possible number in range
        int right = nums.size()-1; //n-highest number in range
        while(left<right)
        {
            int mid = left + (right-left)/2;
            int count=0;
            //count numbers that are less or equal to mid range
            for(int num : nums)
            {
                if(num <= mid)
                {
                    count++;
                }
            }
            //Now if the count is greater than mid it means the dupliacte no lies in the left half
            if(count>mid)
            {
                right=mid;
            }
            else
            {
                left=mid+1;
            }
        }
        return left;
    }
};