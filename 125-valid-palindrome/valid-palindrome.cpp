class Solution {
public:
    char toLowerCase(char ch)
    {
        if(ch>='a' && ch<='z')
        {
            return ch;
        }
        else
        {
            char temp= ch -'A' + 'a';
            return temp;
        }
    }
    string convertString(string s)
    {
        string temp;
        int j=0;
        int i=0;
        while(s[i]!='\0')
        {
            if((s[i]>='0' && s[i]<='9') || (s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))
            {
                temp+=toLowerCase(s[i]);
            }
            i++;
        }
        return temp;
    }
    bool isPalindrome(string s) {
        string newStr=convertString(s);
        int left=0;
        int right=newStr.length()-1;
        while(left<=right)
        {
            if(newStr[left]!=newStr[right])
            {
                return false;
            }
            else
            {
                left++;
                right--;
            }
        }
        return true;
    }
};