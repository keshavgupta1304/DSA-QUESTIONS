class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=1;
        sort(nums.begin(),nums.end());
        int prevEle=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]-prevEle>k)
            {
                ans++;
                prevEle=nums[i];
            } 
        }
        return ans;
    }
};