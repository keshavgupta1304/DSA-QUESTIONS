class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> mp;
        for(auto ch:s) mp[ch]++;
        int evenFreq=INT_MAX;
        int oddFreq=INT_MIN;
        for(auto ele:mp)
        {
            int freq=ele.second;
            if((freq&1)==0) evenFreq=min(evenFreq,freq);
            else oddFreq=max(oddFreq,freq);
        }
        return oddFreq-evenFreq;
    }
};