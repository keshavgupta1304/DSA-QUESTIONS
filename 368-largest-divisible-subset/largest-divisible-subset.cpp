class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n);
        int lastIndex=0;
        int maxi=1;
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int prevInd=0;prevInd<i;prevInd++)
            {
                if(nums[i]%nums[prevInd]==0 && 1+dp[prevInd]>dp[i])
                {
                    dp[i]=1+dp[prevInd];
                    hash[i]=prevInd;
                }
            }
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                lastIndex=i;
            }
        }
        vector<int> answer;
        answer.push_back(nums[lastIndex]);
        while(hash[lastIndex]!=lastIndex)
        {
            lastIndex=hash[lastIndex];
            answer.push_back(nums[lastIndex]);
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};