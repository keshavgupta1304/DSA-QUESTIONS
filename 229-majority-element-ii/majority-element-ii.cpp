class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int occurencesRequired;
        if(n<3)
        {
            occurencesRequired = 1;
        }
        else
        {
            occurencesRequired = n/3 + 1;
        }
        
        unordered_map<int,int> occurences;
        for(auto num:nums)
        {
            occurences[num]++;
        }
        vector<int> ans;
        for(auto val:occurences)
        {
            if(val.second>=occurencesRequired) ans.push_back(val.first);
        }
        return ans;
    }
};