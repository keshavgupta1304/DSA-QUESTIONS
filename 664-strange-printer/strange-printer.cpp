class Solution {
public:
    int strangePrinter(string s) {
        s = removeDuplicate(s);

        int n = s.length();

        vector<vector<int>> memo(n,vector<int>(n,-1));
        return solve(0,n-1,s,memo);
    
    }
    int solve(int start,int end,string& s,vector<vector<int>>& memo)
    {
        if(start>end) return 0;
        if(memo[start][end]!=-1)
        {
            return memo[start][end];
        }
        int minimumTurns=1+solve(start+1,end,s,memo);
        for(int i=start+1;i<=end;i++)
        {
            if(s[i]==s[start])
            {
                int sol=solve(start,i-1,s,memo)+solve(i+1,end,s,memo);
                minimumTurns=min(minimumTurns,sol);
            }
        }
        memo[start][end]=minimumTurns;
        return minimumTurns;
    }
    string removeDuplicate(string s)
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