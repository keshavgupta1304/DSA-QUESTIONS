class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto num:arr)
        {
            mp[num]++;
        }
        for(auto val:mp)
        {
            if(mp.find(val.first*2)!=mp.end())
            {
                if(val.first==0)
                {
                    if(val.second<=1) return false;
                }
                return true;
            } 
        }
        return false;
    }
};