class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        int left=0;
        long long result=0;
        int cnt=0;
        for(int right=0;right<n;right++)
        {
            if(nums[right]==maxi) cnt++;
            while(cnt>=k)
            {
                result+=n-right;
                if(nums[left]==maxi) cnt--;
                left++;
            }
        }
        return result;
    }
};
