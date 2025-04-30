class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt=0;
        for(auto num:nums)
        {
            int digitCnt=log10(num) + 1;
            if((digitCnt&1)==0)
            {
                cnt++;
            }
        }
        return cnt;
    }
};