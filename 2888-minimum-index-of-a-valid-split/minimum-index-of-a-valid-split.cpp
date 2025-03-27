class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixSum(n+1,0);
        int dominantEle=0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(cnt==0)
            {
                dominantEle=nums[i];
                cnt=1;
            }
            else if(nums[i]==dominantEle) cnt++;
            else cnt--;
        }
        prefixSum[0]=0;
        for(int i=0;i<n;i++)
        {
            prefixSum[i+1]=prefixSum[i]+(nums[i]==dominantEle?1:0);
        }
        int minIndex=-1;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]!=dominantEle) continue;
            int leftLen=i+1;
            int rightLen=n-i-1;
            if(2*prefixSum[i+1]>leftLen && 2*(prefixSum[n]-prefixSum[i+1])>rightLen)
            {
                minIndex=i;
                break;
            }
        }
        return minIndex;
    }
};