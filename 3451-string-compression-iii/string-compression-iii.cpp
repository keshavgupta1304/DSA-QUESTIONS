class Solution {
public:
    string compressedString(string word) {
        string comp="";
        if(word.length()==1)
        {
            comp+="1";
            comp+=word[0];
            return comp;
        }
        int i=1;
        int count=1;
        while(i<word.length())
        {
            if(word[i]!=word[i-1] || count==9)
            {
                comp+=to_string(count);
                comp+=word[i-1];
                count=1;
            }
            else
            {
                count++;
            }
            i++;
        }
        comp+=to_string(count);
        comp+=word[word.length()-1];
        return comp;
    }
};