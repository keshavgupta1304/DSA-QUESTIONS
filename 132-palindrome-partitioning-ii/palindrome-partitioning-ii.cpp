class Solution {
public:
    bool isPalindrome(int left,int right,const string& s)
    {
        while(left<right)
        {
            if(s[left]!=s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    int recur(int i,int n,const string& s,vector<int>& dp)
    {   
        if(i==n) return 0; 
        if(dp[i]!=-1) return dp[i];
        int mini=INT_MAX;
        for(int j=i;j<=n-1;j++)
        {
            if(isPalindrome(i,j,s))
            {
                int totalCuts=1+recur(j+1,n,s,dp);
                mini=min(mini,totalCuts);
            }
        }
        return dp[i]=mini;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return recur(0,n,s,dp)-1;
    }
};