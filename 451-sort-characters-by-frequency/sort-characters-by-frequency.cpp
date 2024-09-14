class Solution {
public:
    string frequencySort(string s) {
        string ans="";
        unordered_map<char,int> mp;
        for(auto ch:s)
        {
            mp[ch]++;
        }
        vector<pair<char,int> > vec;
        for(auto pair:mp)
        {
            vec.push_back(pair);
        }
        sort(vec.begin(),vec.end(),[](auto& a,auto& b){
            return a.second>b.second;
        });
        for(auto pair:vec)
        {
            for(int i=0;i<pair.second;i++)
            {
                ans+=pair.first;
            }
        }
        return ans;
    }
};