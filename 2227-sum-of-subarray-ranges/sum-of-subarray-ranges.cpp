class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        long long ans=0;
        long long windowMin;
        long long windowMax; 
        for(int i=0;i<n;i++)
        {
            windowMin=windowMax=nums[i];
            for(int j=i;j<n;j++)
            {
                windowMin=min(windowMin,(long long)nums[j]);
                windowMax=max(windowMax,(long long)nums[j]);
                ans+=windowMax-windowMin;
            }
        }
        return ans;
    }
};