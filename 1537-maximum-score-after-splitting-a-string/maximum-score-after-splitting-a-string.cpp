class Solution {
public:
    int maxScore(string s) {
        int ones=0;
        int zeros=0;
        int maxi=INT_MIN;
        int n=s.size();
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='0') zeros++;
            else ones++;
            maxi=max(maxi,zeros-ones);
        }
        if(s[n-1]=='1') ones++;
        return ones+maxi;

    }
};