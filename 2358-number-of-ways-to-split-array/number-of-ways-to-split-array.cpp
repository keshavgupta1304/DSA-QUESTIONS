class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long> prefixSum(n,0);
        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefixSum[i]=nums[i]+prefixSum[i-1];
        }
        int splits=0;
        for(int i=0;i<n-1;i++)
        {
            if(prefixSum[i]>=prefixSum[n-1]-prefixSum[i]) splits++;
        }
        return splits;

    }
};