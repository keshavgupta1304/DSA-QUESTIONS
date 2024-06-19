class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()<(long long)m * k)
        {
            return -1;
        }
        int left=1;
        int right=1e9;
        while(left<right)
        {
            int mid=left+((right-left)/2);
            if(canMakeBouqets(bloomDay,m,k,mid))
            {
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
    bool canMakeBouqets(vector<int>& bloomDay, int m, int k,int mid){
        int totalNoOfBouqetsFormed=0;
        for(int i=0;i<bloomDay.size();i++)
        {
            int countFlowersThatBloom=0;
            while(i<bloomDay.size() && countFlowersThatBloom < k && bloomDay[i]<=mid)
            {
                countFlowersThatBloom++;
                i++;
            }
            if(countFlowersThatBloom==k)
            {
                totalNoOfBouqetsFormed++;
                i--;
            }
            if(totalNoOfBouqetsFormed>=m)
            {
                return true;
            }
        }
        return false;
    }
};