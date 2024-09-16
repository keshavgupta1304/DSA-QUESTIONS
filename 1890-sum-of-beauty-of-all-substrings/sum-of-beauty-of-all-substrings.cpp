class Solution {
public:
    int beautySum(string s) {
        int sum=0;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            unordered_map<char,int> freq;
            for(int j=i;j<n;j++)
            {
                freq[s[j]]++;
                int maxFrequency=INT_MIN,minFrequency=INT_MAX;
                for(auto it:freq)
                {
                    maxFrequency=max(maxFrequency,it.second);
                    minFrequency=min(minFrequency,it.second);
                }
                sum+=maxFrequency-minFrequency;
            }
        }
        return sum;
    }

};