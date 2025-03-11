class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0;
        int validStrings=0;
        unordered_map<char,int> mp;
        for(int right=0;right<s.size();right++)
        {
            mp[s[right]]++;
            while(mp.size()==3)
            {
                validStrings+=s.size()-right;
                if(--mp[s[left]]==0)
                {
                    mp.erase(s[left]);
                }
                left++;
            }
        }
        return validStrings;

    }
};