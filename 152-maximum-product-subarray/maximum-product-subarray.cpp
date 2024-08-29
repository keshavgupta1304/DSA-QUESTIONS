class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=INT_MIN;
        int n=nums.size();
        int prefix=1;
        int suffix=1;
        for(int left=0;left<n;left++)
        {
            prefix=prefix*nums[left];
            maxi=max(prefix,maxi);
            if(prefix==0) prefix=1;
        }
        for(int right=n-1;right>=0;right--)
        {
            suffix=suffix*nums[right];
            maxi=max(suffix,maxi);
            if(suffix==0) suffix=1;
        }
        return maxi;
    }
};