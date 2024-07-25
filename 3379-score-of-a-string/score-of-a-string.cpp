class Solution {
public:
    int scoreOfString(string s) {
        int ans=0;
        for(int i=1;i<s.length();i++)
        {
            int difference=abs(s[i]-s[i-1]);
            ans+=difference;
        }
        return ans;
    }
};