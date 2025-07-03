class Solution {
public:
    int recur(int i,const vector<int>& nums,vector<int>& dp)
    {
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=nums[i]+recur(i-2,nums,dp);
        int notTake=recur(i-1,nums,dp);
        return dp[i]=max(take,notTake); 
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return recur(nums.size()-1,nums,dp);
    }
};