class Solution {
    using ll=long long;
public:
    long long minArraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<ll> best(k,-LLONG_MAX);best[0]=0;//max value of dp[j]-prefix[j] for every mod value
        vector<ll> dp(n),prefix(n);//dp[i]=max sum removable from [0..i] prefix ->prefix Sum
        for(int i=0;i<n;i++)
        {
            prefix[i]+=nums[i];
            if(i) prefix[i]+=prefix[i-1],dp[i]=dp[i-1];
            if(best[prefix[i]%k]!=-LLONG_MAX)
            {
                dp[i]=max(dp[i],prefix[i]+best[prefix[i]%k]);
            }
            best[prefix[i]%k]=max(best[prefix[i]%k],dp[i]-prefix[i]);
        }
        ll totalSum=0;
        for(auto &x:nums) totalSum+=x;
        return totalSum-dp[n-1];
    }
};