class Solution {
    using ll=long long;
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        ll base=0;
        int n=prices.size();
        for(int i=0;i<n;i++) base+=prices[i]*strategy[i];
        ll ans=base;
        for(int i=0;i<k;i++) base-=prices[i]*strategy[i];
        ll slide=0;
        for(int i=k/2;i<k;i++) slide+=prices[i];
        ans=max(ans,base+slide);
        for(int i=k;i<n;i++)
        {
            base-=prices[i]*strategy[i];
            base+=prices[i-k]*strategy[i-k];
            slide-=prices[i-k/2];
            slide+=prices[i];
            ans=max(ans,base+slide);
        }
        return ans;
    }
};