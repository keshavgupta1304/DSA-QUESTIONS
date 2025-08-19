class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        long long cnt=0;
        int streak=0;
        for(auto num:nums)
        {
            if(num==0)
            {
                streak++;
                cnt+=streak;
            }
            else streak=0;
        }
        return cnt;
    }
};