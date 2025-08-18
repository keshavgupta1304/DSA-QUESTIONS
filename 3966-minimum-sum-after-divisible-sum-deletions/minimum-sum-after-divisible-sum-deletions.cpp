class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> dp(n+1,0);//max sum we can remove
        map<int,long long> mp;
        mp[0]=0LL; //j..i-1 tk ka array hoga jo remove ho skta hoga  dp[j]+(prefix[i]-prefix[j])->
        //(dp[j] - prefix[j]) + prefix[i]
        long long prefix=0;
        for(int i=1;i<=n;i++)
        {
            prefix+=nums[i-1];
            int rem=(int) (prefix%k);
            dp[i]=dp[i-1];//skip
            if(mp.count(rem))
            {
                long long candidate=mp[rem]+prefix;
                dp[i]=max(dp[i],candidate);
            }
            long long val=dp[i]-prefix;
            mp[rem] = max(mp.count(rem) ? mp[rem] : LLONG_MIN, val);
        }
        long long totalSum=0;
        for(auto &num:nums) totalSum+=num;
        return totalSum-dp[n];
    }
};