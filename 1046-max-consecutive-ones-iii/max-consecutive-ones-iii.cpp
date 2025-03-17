class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int n=nums.size();
        int numZeros=0;
        int ans=0;
        for(int right=0;right<n;right++)
        {
            if(!nums[right]) numZeros++;
            if(numZeros>k)
            {
                while(numZeros!=k)
                {
                    if(!nums[left]) numZeros--;
                    left++;
                }
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};