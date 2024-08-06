class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> freq;
        for(auto ch:word)
        {
            freq[ch]++;
        }
        vector<pair<char, int> > frequency; 
        for (auto& it : freq) { 
            frequency.push_back(it); 
        } 
        sort(frequency.begin(),frequency.end(),[&](pair<char,int> &a,pair<char,int> &b){
            return a.second>b.second;
        });
        int n=frequency.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int multiplier=(i/8)+1;
            ans+=multiplier*(frequency[i].second);
        }
        return ans;
    }
};