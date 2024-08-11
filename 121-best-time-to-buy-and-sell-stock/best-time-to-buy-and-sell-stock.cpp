class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        
        int left=0;
        for(int i=1;i<prices.size();i++)
        {
            int buy=prices[left];
            int sell=prices[i];
            int profit=sell-buy;
            if(profit<0)
            {
                profit=0;
                left=i;
            }
            ans=max(ans,profit); 
        }
        return ans;
    }
};