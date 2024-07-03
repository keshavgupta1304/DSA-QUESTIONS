class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> freq_count;
        int left=0;
        int right=0;
        int ans=0;
        while(right<s.size())
        {
            freq_count[s[right]]++;

            while(freq_count[s[right]]>1)
            {
                freq_count[s[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};