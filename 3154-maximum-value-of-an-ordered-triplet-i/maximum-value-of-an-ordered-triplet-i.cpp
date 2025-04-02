class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi=0;
        for(int i=0;i<nums.size()-2;i++)
        {
            for(int j=i+1;j<nums.size()-1;j++)
            {
                int diff=nums[i]-nums[j];
                for(int k=j+1;k<nums.size();k++)
                {
                    maxi=max(maxi,(long long)nums[k]*(diff));
                }
            }
            
        }
        return maxi;
    }
};