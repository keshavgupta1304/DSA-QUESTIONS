class Solution {
public:
    int lenLongestPalindrome(string& s) {
        string t(s.rbegin(), s.rend());
        int n=s.size();
        vector<int> prev(n+1);
        vector<int> curr(n+1);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1]) curr[j]=1+prev[j-1];
                else curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[n];
    }
    int minInsertions(string s) {
        return s.size()-lenLongestPalindrome(s);
    }
};