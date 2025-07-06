class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum&1) return false;
        int target=sum/2;
        vector<bool> prev(target+1,false);
        vector<bool> cur(target+1,false);
        prev[0]=cur[0]=true;
        if(nums[0]<=target)
        {
            prev[nums[0]]=true;
        }
        for(int i=1;i<n;i++)
        {
            for(int k=1;k<=target;k++)
            {
                bool notTaken=prev[k];
                bool taken=false;
                if(nums[i]<=k)
                {
                    taken=prev[k-nums[i]];
                }
                cur[k]=notTaken || taken;
            }
            prev=cur;
        }
        return prev[target];
    }
};