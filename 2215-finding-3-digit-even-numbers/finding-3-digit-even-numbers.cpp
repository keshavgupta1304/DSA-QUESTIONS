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
            unordered_map<int,int> tempMap=mp;
            if(tempMap[hundreds]-- > 0 && tempMap[tens]-- > 0 && tempMap[ones]-- > 0)
            {
                ans.push_back(num);
            }
        }
        return ans;
    }
};