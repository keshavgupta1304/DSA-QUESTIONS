class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long result=0;
        int left=0;
        int n=nums.size();
        int prevEle=-1;
        long long pairs=0;
        unordered_map<int,int> mp;
        for(int right=0;right<n;right++)
        {
            pairs+=mp[nums[right]];
            mp[nums[right]]++;
            while(pairs>=k)
            {
                result+=n-right;
                mp[nums[left]]--;
                pairs-=mp[nums[left]];
                left++;
            }
        }
        return result;
    }
};