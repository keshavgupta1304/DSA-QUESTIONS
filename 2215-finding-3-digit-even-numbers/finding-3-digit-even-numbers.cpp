class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(auto digit:digits)
        {
            mp[digit]++;
        }
        for(int num=100;num<=999;num++)
        {
            if(num&1) continue;
            int hundreds=num/100;
            int tens=(num/10)%10;
            int ones=num%10;
            mp[hundreds]--;
            mp[tens]--;
            mp[ones]--;
            if(mp[hundreds] >= 0 && mp[tens] >= 0 && mp[ones] >= 0)
            {
                ans.push_back(num);
            }
            mp[hundreds]++;
            mp[tens]++;
            mp[ones]++;
        }
        return ans;
    }
};