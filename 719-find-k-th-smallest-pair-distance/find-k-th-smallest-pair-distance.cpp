class Solution {
private:
    int findPairsOfMaxDistanceMid(vector<int>& nums,int maxDistance)
    {
        int left=0;
        int ans=0;
        for(int right=0;right<nums.size();right++)
        {
            while(nums[right]-nums[left]>maxDistance)
            {
                left++;
            }
            ans+=right-left;
        }
        return ans;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int low=0;
        int high=nums[nums.size()-1]-nums[0];
        while(low<high)
        {
            int mid=low+(high-low)/2;
            int countPairs=findPairsOfMaxDistanceMid(nums,mid);
            if(countPairs<k) low=mid+1;
            else high=mid;
        }
        return low;
    }
};