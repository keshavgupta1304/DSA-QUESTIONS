class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(auto& operation:logs)
        {
           if(operation=="../" && ans!=0)
           {
                ans=ans-1;
           }
           else if(operation=="../" && ans==0)
           {
                ans=ans+0;
           }
           else if(operation=="./")
           {
                ans=ans+0;
           }
           else
           {
                ans=ans+1;
           }
        }
        return ans;
    }
};