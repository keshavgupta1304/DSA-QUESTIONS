class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans=0;
        double arrivalTime = customers[0][0];
        double finishTime = arrivalTime + customers[0][1];
        ans = finishTime - arrivalTime;
        for(int i=1;i<customers.size();i++)
        {
            if(finishTime <= customers[i][0])
            {
                arrivalTime=customers[i][0];
            }
            else
            {
                arrivalTime = finishTime;
            }
            
            finishTime = arrivalTime + customers[i][1];
            ans += finishTime - customers[i][0];
        }
        cout<<fixed;
        cout<<setprecision(5);
        return double(ans/customers.size());
    }
};