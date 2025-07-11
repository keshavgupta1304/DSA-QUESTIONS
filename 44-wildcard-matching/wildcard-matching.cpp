class Solution {
public:
    bool isAllStars(const string& p,int j)
    {
        for(int i=0;i<=j;i++)
        {
            if(p[i]!='*') return false;
        }
        return true;
    }
    int recur(int i,int j,const string& s,const string& p,vector<vector<int>>& dp)
    {
        if(i==0 && j==0) return true;
        if(i>0 && j==0) return false;
        if(i==0 && j>=1) return isAllStars(p,j-1);
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==p[j-1] || p[j-1]=='?') return dp[i][j]=recur(i-1,j-1,s,p,dp);
        else
        {
            if(p[j-1]=='*') return dp[i][j]=recur(i-1,j,s,p,dp) || recur(i,j-1,s,p,dp);
            else return false;
        }
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return recur(n,m,s,p,dp);
    }
};