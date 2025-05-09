class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        vector<int> prefixXor(n);
        prefixXor[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefixXor[i]=prefixXor[i-1]^nums[i];
        }
        vector<int> result(n);
        int mask=(1<<maximumBit)-1;
        for(int i=0;i<n;i++)
        {
            int currentXor=prefixXor[n-i-1];
            result[i]=currentXor^mask;
        }
        return result;
    }
};