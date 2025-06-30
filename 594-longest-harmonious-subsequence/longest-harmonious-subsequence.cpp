class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        for(auto num:nums)
        {
            mp[num]++;
        }
        if(mp.size()==1) return 0;
        int ans=0;
        for(auto [num,freq]:mp)
        {
            if(mp.find(num-1)!=mp.end()) ans=max(ans,freq+mp[num-1]);
        }
        return ans;
    }
};