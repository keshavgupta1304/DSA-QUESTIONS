class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st;
        for(auto num:nums)
        {
            st.insert(num);
        }
        int result=0;
        for(int i=0;i<nums.size();i++)
        {
            unordered_set<int> temp;
            for(int j=i;j<nums.size();j++)
            {
                temp.insert(nums[j]);
                if(temp.size()==st.size()) result++;
            }
            temp.clear();
        }
        return result;
    }
};