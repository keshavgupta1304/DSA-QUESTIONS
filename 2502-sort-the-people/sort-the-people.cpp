class Solution {
public:
    
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
        map<int,string,greater<int>> mp;
        for(int i=0;i<names.size();i++)
        {
            mp[heights[i]]=names[i];
        }
        for(auto val:mp)
        {
            ans.push_back(val.second);
        }
        return ans;
    }
};