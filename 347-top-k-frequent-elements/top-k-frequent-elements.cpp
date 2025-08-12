class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans(k);
        unordered_map<int,int> mp;
        for(auto num:nums) mp[num]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto [num,freq]:mp)
        {
            pq.push({freq,num});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        int i=0;
        while(!pq.empty())
        {
            ans[i++]=pq.top().second;
            pq.pop();
        }
        return ans;
    }
};