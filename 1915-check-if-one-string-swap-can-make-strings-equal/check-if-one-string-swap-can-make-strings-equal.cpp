class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int i=0;
        int diffChar=0;
        int s1Freq[26]={0};
        int s2Freq[26]={0};
        while(i<s1.size())
        {
            if(s1[i]!=s2[i])
            {
                diffChar++;
                if(diffChar>2) return false;
            }
            s1Freq[s1[i]-'a']++;
            s2Freq[s2[i]-'a']++; 
            i++;
        }
        for(int i=0;i<26;i++)
        {
            if(s1Freq[i]!=s2Freq[i]) return false;
        }
        return true;
    }
};