class Solution {
private:
    bool canFinish(long long minutes,vector<int>& ranks, int cars)
    {
        long long noOfCarsRepaired=0;
        for(int i=0;i<ranks.size();i++)
        {
            long long calc=minutes/ranks[i];
            noOfCarsRepaired+=calc>0?sqrt(calc):0;
            if(noOfCarsRepaired>=cars) return true;
        }
        return false;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long result=0;
        long long minRank=*min_element(ranks.begin(),ranks.end());
        long long left=1;
        long long n=(long long)cars;
        long long right=(long long)(minRank*(long long)(n*n));
        while(left<=right)
        {
            long long mid=left+(right-left)/2;
            if(canFinish(mid,ranks,cars))
            {
                result=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return result;
    }
};