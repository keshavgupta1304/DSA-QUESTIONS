class Solution {
public:
    int minSwaps(vector<int>& nums) {
        set<int> swapsStored;
        int swaps=0;
        int total=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1) total++;
        }
        for(int i=0;i<total;i++)
        {
            if(nums[i]==0) swaps++;
        }
        swapsStored.insert(swaps);
        if(swaps==0) return 0;
        for(int i=total;i<n+total-1;i++)
        {
            int number_out=nums[i-total];
            int number_in=nums[i%n];
            if(number_out==0 && number_in==1) swaps--;
            if(number_out==1 && number_in==0) swaps++;
            swapsStored.insert(swaps);
        }
        set<int>::iterator it = swapsStored.begin();

        return *it;
    }
};