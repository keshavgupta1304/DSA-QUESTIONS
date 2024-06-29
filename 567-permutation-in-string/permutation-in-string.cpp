class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        if(s2.size()<s1.size())
        {
            return false;
        }
        unordered_map<char,int> freq_s1;
        unordered_map<char,int> freq_s2;
        for(int i=0;i<s1.length();i++)
        {
            freq_s1[s1[i]]++;
            freq_s2[s2[i]]++;
        }

        if(freq_s1 == freq_s2)
        {
            return true;
        }

        for(int i=s1.length();i<s2.length();i++)
        {
            char ch_out=s2[i-s1.length()];
            if(freq_s2[ch_out] == 1)
            {
                freq_s2.erase(ch_out);
            }
            else
            {
                freq_s2[ch_out]--;
            }

            char ch_in=s2[i];
            freq_s2[ch_in]++;

            if(freq_s1 == freq_s2)
            {
                return true;
            }

        }
        return false;
    }
};