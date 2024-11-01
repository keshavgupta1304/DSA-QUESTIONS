class Solution {
public:
    string makeFancyString(string s) {
        char ch=s[0];
        int count=1;
        string temp="";
        temp+=ch;
        for(int i=1;i<s.length();i++)
        {
            if(ch==s[i])
            {
                count++;
                if(count>=3)
                {
                    continue;
                }
            }
            else
            {
                ch=s[i];
                count=1;
            }
            temp+=s[i];
        }
        return temp;
    }
};