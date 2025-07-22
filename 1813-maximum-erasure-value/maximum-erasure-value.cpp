class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int maxScore=0;
        int localMax=0;
        unordered_set<int> st;
        for(int right=0;right<n;right++)
        {
            while(!st.empty() && st.find(nums[right])!=st.end())
            {
                st.erase(nums[left]);
                localMax-=nums[left];
                left++;
            }
            st.insert(nums[right]);
            localMax+=nums[right];
            maxScore=max(maxScore,localMax);
        }
        return maxScore;
    }
};