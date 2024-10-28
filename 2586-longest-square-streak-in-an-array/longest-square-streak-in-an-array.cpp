class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int maxStreak=0;
        unordered_map<int,int> mp;
        for(auto num:nums)
        {
            mp.insert({num,1});
        }
        for(int i=0;i<nums.size();i++)
        {
            int num=nums[i];
            int streak=0;
            while(true)
            {
                if(mp.find(num)!=mp.end())
                {
                    streak++;
                    if(num>sqrt(pow(10,5))) break;
                    num=num*num;
                }
                else
                {
                    break;
                }
            }
            maxStreak=max(maxStreak,streak);
        }
        return maxStreak<2?-1:maxStreak;
    }
};