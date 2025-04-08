class Solution {
private:
    bool checkDistinct(unordered_map<int,int>& mp)
    {
        for(auto [ele,freq]:mp)
        {
            if(freq>1) return false;
        }
        return true;
    }
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        int result=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        bool isDistinct=checkDistinct(mp);
        int i=0;
        int multiplier=1;
        while(isDistinct==false)
        {
            while(i<n && i<3*multiplier)
            {
                mp[nums[i]]--;
                i++;
            }
            isDistinct=checkDistinct(mp);
            multiplier++;
            result++;
        }
        return result;
    }
};