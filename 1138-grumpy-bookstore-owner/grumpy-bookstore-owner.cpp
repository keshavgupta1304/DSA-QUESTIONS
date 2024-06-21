class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int maxCustomers=0;
        for(int i=0;i<grumpy.size();i++)
        {
            if(grumpy[i]==0)
            {
                maxCustomers+=customers[i];
            }
        }
        int maxSum=0;

        for(int i=0;i<minutes;i++)
        {
            if(grumpy[i])
            {
                maxSum+=customers[i];
            }
        }
        int windowSum=maxSum;
        for(int i=minutes;i<customers.size();i++)
        {
            if(grumpy[i-minutes])
            {
                windowSum-=customers[i-minutes];
            }
            if(grumpy[i])
            {
                windowSum+=customers[i];
            }
            maxSum=max(maxSum,windowSum);
        }
        return maxCustomers+maxSum;
    }
};