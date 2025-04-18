class Solution {
private:
    string runLenEnc(string s)
    {
        int cnt=0;
        string result="";
        char ch;
        for(int i=0;i<s.length();i++)
        {
            if(cnt==0)
            {
                ch=s[i];
                cnt=1;
            }
            else if(s[i]!=ch)
            {
                result+=to_string(cnt)+ch;
                ch=s[i];
                cnt=1;
            }
            else
            {
                cnt++;
            }
        }
        if(cnt>0) result+=to_string(cnt)+ch;
        return result;
    }
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string curr=countAndSay(n-1);
        return runLenEnc(curr);
    }
};