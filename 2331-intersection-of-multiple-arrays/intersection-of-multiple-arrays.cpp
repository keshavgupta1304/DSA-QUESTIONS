class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int,int>mp;
        vector<int>v;
      for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums[i].size();j++){
            mp[nums[i][j]]++;
        }
      }
        int n=nums.size();
        for(auto i=mp.begin();i!=mp.end();i++){
            if(i->second==n){
                v.push_back(i->first);
            }
        
      }
      sort(v.begin(),v.end());
      return v;  
    }
};