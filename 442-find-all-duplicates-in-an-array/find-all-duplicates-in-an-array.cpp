class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> mp;
        // map to store number and its occurence
        for(auto num:nums)
        {
            mp[num]++;
        }
        vector<int> ans;
        for(auto n:mp)
        {
            if(n.second==2)
            {
                ans.push_back(n.first);
            }
        }
        return ans;
    }
};