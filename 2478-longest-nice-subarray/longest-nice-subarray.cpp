class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans=1;
        int left=0;
        int right=0;
        int n=nums.size();
        int bitAnd=nums[0];
        while(right<n)
        {
            if(left==right){
                right++;
                continue;
            }
            for(int i=left;i<right;i++)
            {
                bitAnd=nums[i]&nums[right];
                if(bitAnd!=0)
                {
                    left=i+1;
                }
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};