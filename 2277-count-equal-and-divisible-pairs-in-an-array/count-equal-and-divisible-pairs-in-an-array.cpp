class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int res=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int ele=nums[i];
            for(int j=i+1;j<n;j++)
            {
                if((i*j)%k==0)
                {
                    res+=nums[j]==ele?1:0;
                }
            }
        }
        return res;
    }
};