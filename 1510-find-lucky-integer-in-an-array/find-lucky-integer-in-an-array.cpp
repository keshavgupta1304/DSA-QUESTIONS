class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans=-1;
        map<int,int> mp;
        for(auto num:arr)
        {
            mp[num]++;
        }
        for(auto [num,freq]:mp)
        {
            if(num==freq)
            {
                ans=num;
            }
        }
        return ans;
    }
};