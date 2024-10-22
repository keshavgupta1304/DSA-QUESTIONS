class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string temp="";
        int i=0,j=0;
        while(i<word1.length() && j<word2.length())
        {
            temp += word1[i];
            temp += word2[j];
            i++;
            j++;
        }
        while(i<word1.length())
        {
            temp+=word1[i];
            i++;
        }
        while(j<word2.length())
        {
            temp+=word2[j];
            j++;
        }
        return temp;
    }
};