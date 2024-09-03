class Solution {
private:
    bool isValid(vector<int>& bloomDay,int mid, int m, int k)
    {
        //mid is no of Days here.m is required bouqets,k is adjacent flowers
        int cntAdjacent=0;
        int noOfBouqets=0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=mid)//bloomedFlowers
            {
                cntAdjacent+=1;
                if(cntAdjacent==k)
                {
                    noOfBouqets+=1;
                    cntAdjacent=0;
                }
            }
            else
            {
                cntAdjacent=0;
            }
        }
        return noOfBouqets>=m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(n<(long long)m*k)
        {
            return -1;
        }
        int low=1;
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=INT_MAX;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isValid(bloomDay,mid,m,k))
            {
                ans=min(mid,ans);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};