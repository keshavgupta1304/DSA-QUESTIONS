class Solution {
public:

    bool isPossibleSol(vector<int>& piles, int h,int mid)
    {
        double noOfHours=0;
        int noOfBananas=mid;
        for(int i=0;i<piles.size();i++)
        {
            noOfHours+=ceil((double)piles[i]/mid);
            if(noOfHours>h)
            {
                return false;
            }
        }
        return noOfHours<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left=0;
        int right=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(isPossibleSol(piles,h,mid))
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