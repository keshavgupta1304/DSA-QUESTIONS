class Solution {
public:
    bool helper(const string &a,const string &b)
    {
        int n1=a.size();
        int n2=b.size();
        if((n1-n2)!=1) return false;
        int i=0;
        int j=0;
        while(i<n2 && j<n1)
        {
            if(b[i]==a[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return i==n2;
    }
    int recur(int index,int prevIndex,const vector<string>& words,vector<vector<int>>& dp)
    {
        if(index==words.size()) return 0;
        if(dp[index][prevIndex]!=-1) return dp[index][prevIndex];
        int maxi=recur(index+1,prevIndex,words,dp);
        if(prevIndex==0 || helper(words[index],words[prevIndex-1]))
        {
            maxi=max(maxi,1+recur(index+1,index+1,words,dp));
        }
        return dp[index][prevIndex]=maxi;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string &a,string &b){
            return a.size()<b.size();
        });
        int n=words.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return recur(0,0,words,dp);
    }
};