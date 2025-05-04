class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int res=0;
        unordered_map<int,int> mp;
        for(auto it:dominoes)
        {
            int value=0;
            if(it[0]<it[1]) 
            {
                value=it[0]*10 + it[1];
            }
            else
            {
                value=it[1]*10 + it[0];
            }
            res+=mp[value];
            mp[value]++;
        }
        return res;
    }
};