class Solution {
public:
    void generateSubstring(int n,string &s,vector<string> &result,int index)
    {
        if(index>=n)
        {
            result.push_back(s);
            return;
        }
        if(s[index-1]=='0')
        {
            s[index]='1';
            generateSubstring(n,s,result,index+1);
        }
        if(s[index-1]=='1')
        {
            s[index]='1';
            generateSubstring(n,s,result,index+1);
            s[index]='0';
            generateSubstring(n,s,result,index+1);
        }
    }
    vector<string> validStrings(int n) {
        vector<string> result;
        string s(n,'0');
        s[0]='0';
        generateSubstring(n,s,result,1);
        s[0]='1';
        generateSubstring(n,s,result,1);
        return result;
    }
};