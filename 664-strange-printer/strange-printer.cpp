class Solution {
public:
    int strangePrinter(string s) {
        s = removeDupli(s);
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        for(int length=2;length<=n;length++)
        {
            for(int start=0;start<=n-length;start++)
            {
                int end=start+length-1;
                dp[start][end] = length;
                
                for(int split=0;split<length-1;split++)
                {
                    int totalOperations = dp[start][start+split] + dp[start+split+1][end];
                    if(s[start+split]==s[end]) totalOperations--;
                    dp[start][end]=min(dp[start][end],totalOperations);
                }
            }
        }
        return dp[0][n-1];
    }
    string removeDupli(string s)
    {
        string ans;
        int i=0;
        while(i<s.length())
        {
            char current=s[i];
            ans+=current;
            while(i<s.length() && s[i]==current)
            {
                i++;
            }
        }
        return ans;
    }
};