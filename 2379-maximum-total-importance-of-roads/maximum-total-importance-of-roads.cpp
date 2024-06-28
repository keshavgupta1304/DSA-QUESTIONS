class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<long long,long long> freq;
        for(auto num:roads)
        {
            for(auto value:num)
            {
                freq[value]++;
            }
        }
        vector<pair<long long, long long> > pairs;
        for (auto& it : freq) { 
            pairs.push_back(it); 
        } 
        sort(pairs.begin(), pairs.end(), [](auto& a, auto& b) { 
        return a.second > b.second; 
        });
        vector<long long> assigned(n);
        int i=n;
        for(auto pair:pairs)
        {
            assigned[pair.first]=i;
            i--;
        }
        long long sum=0;
        for(auto pair:pairs)
        {
            long long val = (freq[pair.first]) * (assigned[pair.first]);
            sum=sum+val;
        }
        return sum;
    }
};