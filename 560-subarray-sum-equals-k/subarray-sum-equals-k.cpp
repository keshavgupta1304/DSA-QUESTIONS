class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        unordered_map<int,int> mp;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum==k)
            {
                count=count+1;
            }
            int remaining=sum-k;
            if(mp.find(remaining)!=mp.end())
            {
                count=count+mp[remaining];
            }
            mp[sum]++;
        }
        return count;
    }
};