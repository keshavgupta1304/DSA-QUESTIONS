class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        int n=nums.size();
        int len=1;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(nums[i]>temp.back())
            {
                temp.push_back(nums[i]);
                len++;
            }
            else
            {
                int index=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[index]=nums[i];
            }
        }
        return len;
    }
};