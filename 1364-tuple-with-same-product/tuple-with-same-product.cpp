class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int tuples=0;
        if(nums.size()<4) return tuples;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int product=nums[i]*nums[j];
                tuples+=8*mp[product];
                mp[product]++;
            }
        }
        return tuples;
    }
};