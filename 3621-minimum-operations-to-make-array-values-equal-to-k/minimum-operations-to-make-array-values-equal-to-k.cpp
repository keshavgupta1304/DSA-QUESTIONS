class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int result=0;
        unordered_set<int> set(nums.begin(),nums.end());
        for(auto num:set)
        {
            if(num==k) continue;
            else if(num>k) result++;
            else return -1;
        }
        return result;
    }
};