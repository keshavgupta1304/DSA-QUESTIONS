class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int> freq;
        for(auto ch:allowed)
        {
            freq[ch]=1;
        }
        int count=0;
        for(auto word:words)
        {
            int i;
            for(i=0;i<word.length();i++)
            {
                if(freq.find(word[i])==freq.end())
                {
                    break;
                }
            }
            if(i==word.length()) count++;
        }
        return count;
    }
};