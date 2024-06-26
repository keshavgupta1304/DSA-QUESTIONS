class Solution {
public:

    bool isPossibleSol(vector<int>& weights, int days, int mid)
    {
        int countDays=1;
        int sumOfWeights=0;
        for(int i=0;i<weights.size();i++)
        {
            if(sumOfWeights + weights[i] <= mid)
            {
                sumOfWeights+=weights[i];
            }
            else
            {
                countDays++;
                if(countDays>days || weights[i]>mid)
                {
                    return false;
                }
                sumOfWeights=weights[i];
            }
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left=0;
        int sum=0;
        for(int i=0;i<weights.size();i++)
        {
            sum+=weights[i];
        }
        int right=sum;
        int ans=-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(isPossibleSol(weights,days,mid))
            {
                ans=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return ans;
    }
};