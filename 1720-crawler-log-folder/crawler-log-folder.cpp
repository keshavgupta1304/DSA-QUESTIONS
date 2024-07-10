class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(auto& operation:logs)
        {
           if(operation=="../")
           {
                if(ans>0) ans--;
           }
           else if(operation!="./")
           {
                ans++;
           }  
        }
        return ans;
    }
};