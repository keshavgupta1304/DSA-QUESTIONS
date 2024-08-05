class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int countOfZeros=0;
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                countOfZeros++;
            } 
            else
            {
                nums[j]=nums[i];
                j++;
            }
        }
        int n=j+countOfZeros;
        for(;j<n;j++)
        {
            nums[j]=0;
        }
    }
};