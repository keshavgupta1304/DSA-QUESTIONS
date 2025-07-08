class Solution {
public:
    int lcs(const string& s,const string &t) {
        int n1=s.size();
        int n2=t.size();
        vector<int> prev(n2+1);
        vector<int> curr(n2+1);
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(s[i-1]==t[j-1]) curr[j]=1+prev[j-1];
                else curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[n2];
    }
    int minDistance(string word1, string word2) {
        return word1.size()+word2.size()-2*lcs(word1,word2);
    }
};