class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                mp[0].push_back(nums[i]);
            }
            else
            {
                mp[1].push_back(nums[i]);
            }
        }
        int itr=0;
        for(int i=0;i<mp[0].size();i++)
        {
            ans.push_back(mp[0][i]);
            ans.push_back(mp[1][i]);
        }
        return ans;
    }
};