class Solution {
public:
    int possibleStringCount(string word, int k) {
        const int mod = 1e9 + 7;
        int n = word.size();
        vector<int> cnts;
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && word[j] == word[i])
                j++;
            cnts.push_back(j - i);
            i = j;
        }

        long total=1;
        for(auto cnt:cnts)
        {
            total=(total*cnt)%mod;
        }
        if(k<=cnts.size()) return total;
        vector<int> dp(k,0);
        dp[0]=1;
        for(auto group:cnts)
        {
            vector<int> newDp(k,0);
            long sum=0;
            for(int s=0;s<k;s++)
            {
                if(s>0)
                {
                    sum=(sum+dp[s-1])%mod;
                }
                if(s>group) sum=(sum-dp[s-group-1]+mod)%mod;
                newDp[s]=sum;
            }
            dp=newDp;
        }

        for(int s=cnts.size();s<k;s++)
        {
            total=(total-dp[s]+mod)%mod;
        }
        return total;
    }
};