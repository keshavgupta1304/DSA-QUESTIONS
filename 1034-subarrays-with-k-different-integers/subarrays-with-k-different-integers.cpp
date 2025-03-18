class Solution {
private:
    int subarrayWithAtMostK(vector<int>& nums, int k)
    {
        int total=0;
        int left=0;
        unordered_map<int,int> mp;
        for(int right=0;right<nums.size();right++)
        {
            mp[nums[right]]++;
            while(left<=right && mp.size()>k)
            {
                if(--mp[nums[left]]==0) mp.erase(nums[left]);
                left++;
            }
            total+=right-left+1;
        }
        return total;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrayWithAtMostK(nums,k)-subarrayWithAtMostK(nums,k-1);
    }
};