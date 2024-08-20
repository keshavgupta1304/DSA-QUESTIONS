class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> mp;
        for(auto val:nums)
        {
            mp[val]=true;
        }
        int ans=INT_MIN;
        for(auto val:nums)
        {
            if(mp.find(val-1)!=mp.end()) continue;
            int count=0;
            for(int i=val;i<INT_MAX;i++)
            {
                if(mp.find(i)==mp.end())
                {
                    break;
                }
                count++;
            }
            ans=max(ans,count);
        }
        return ans==INT_MIN?0:ans;
    }
};