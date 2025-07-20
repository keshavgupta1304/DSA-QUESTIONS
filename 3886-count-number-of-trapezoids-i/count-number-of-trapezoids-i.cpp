class Solution {
public:
    const int mod=1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
        //har same y ke liye pairs bna lenge
        unordered_map<int,int> mp;
        for(auto &point:points)
        {
            int y=point[1];
            mp[y]++;
        }
        long long pairs=0;
        long long prefixPairs=0;
        for(auto [y,freq]:mp){
            if(freq>=2)
            {
                long long currentPair=(long long)freq*(freq-1)/2;
                pairs = (pairs + prefixPairs * currentPair) % mod;
                prefixPairs=(prefixPairs+currentPair)%mod;
            }
        }
        return pairs;
    }

};