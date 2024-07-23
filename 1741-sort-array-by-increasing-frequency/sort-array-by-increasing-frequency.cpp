class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<pair<int,int>> freqCount;
        for(auto num:nums)
        {
            mp[num]++;
        }
        for(auto& it : mp)
        { 
            freqCount.push_back(it); 
        }
        sort(freqCount.begin(), freqCount.end(), [](auto& a, auto& b) { 
            if(a.second!=b.second)
            {
                return a.second<b.second;
            } 
            return a.first>b.first;
        });
        vector<int> ans;
        for(auto val:freqCount)
        {
            for(int i=0;i<mp[val.first];i++)
            {
                ans.push_back(val.first);
            }
        }
        return ans;

    }
};