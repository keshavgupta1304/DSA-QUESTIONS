class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            string odd=expand(s,i,i);
            if(odd.size()>ans.size())
            {
                ans=odd;
            }
            string even=expand(s,i,i+1);
            if(even.size()>ans.size())
            {
                ans=even;
            }
        }
        return ans;
    }
    string expand(string s,int i,int j)
    {
        int left=i;
        int right=j;
        while(left>=0 && right<s.length() && s[left]==s[right])
        {
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
    }
};
