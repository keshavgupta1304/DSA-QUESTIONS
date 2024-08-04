class Solution {
public:
    const int MOD = 1'000'000'007;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> subarraySums;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=nums[j]%(MOD);
                subarraySums.push_back(sum);
            }
        }
        sort(subarraySums.begin(),subarraySums.end());
        int ans=0;
        for(int i=left-1;i<right;i++)
        {
            ans=(ans%MOD+subarraySums[i]%(MOD))%(MOD);
        }
        return (int)ans;
    }
};