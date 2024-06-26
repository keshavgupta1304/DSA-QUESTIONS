class Solution {
public:

    bool isPossibleSol(vector<int>& bloomDay, int m, int k,int mid)
    {
        int noOfBouqets=0;
        int noOfFlowers=0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=mid)
            {
                noOfFlowers++;
            }
            else
            {
                noOfFlowers=0;
            }
            if(noOfFlowers == k)
            {
                noOfBouqets++;
                noOfFlowers=0;
            }
        }
        return noOfBouqets>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k > bloomDay.size())
        {
            return -1;
        }
        long long left=0;
        long long right=INT_MAX;
        long long minNoOfDays=-1;
        while(left<=right)
        {
            long long mid=left+(right-left)/2;
            if(isPossibleSol(bloomDay,m,k,mid))
            {
                minNoOfDays=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return (int)minNoOfDays;
    }
};