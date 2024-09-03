class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        if(piles.size()==h) return high;
        int k = INT_MAX;
        while(low<=high)
        {
            int mid = low + (high-low)/2;//banana-per-hour
            if(checkValid(mid,piles,h))
            {
                k=min(k,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return k;
    }
    bool checkValid(int mid,vector<int>& piles,int h)
    {
        long long noOfHours=0;
        for(auto bananas:piles)
        {
            if(bananas%mid==0) noOfHours+=bananas/mid;
            else noOfHours+=(bananas/mid)+1;
        }
        return noOfHours<=h?true:false;
    }
};