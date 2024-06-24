class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int ans=0;
        int currentFlips=0;//track flips in the current window
        for(int i=0;i<nums.size();++i)
        {
            if(i>=k && nums[i-k]==2)
            {
                currentFlips--;
            }
            if((currentFlips%2)==nums[i])
            {
                if((i+k)> nums.size())
                {
                    return -1;
                }
                nums[i]=2;
                currentFlips++;
                ans++;
            }
        }
        return ans;
    }
};