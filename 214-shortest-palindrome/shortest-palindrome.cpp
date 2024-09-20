class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.length();
        if(n==0) return s;
        int left=0;
        for(int right=n-1;right>=0;right--)
        {
            if(s[left]==s[right])
            {
                left++;
            }
        }
        if(left==n) return s;

        string suffix=s.substr(left);
        string reverseSuffix = string(suffix.rbegin(), suffix.rend());

        return reverseSuffix + shortestPalindrome(s.substr(0, left)) + suffix;
    }
};