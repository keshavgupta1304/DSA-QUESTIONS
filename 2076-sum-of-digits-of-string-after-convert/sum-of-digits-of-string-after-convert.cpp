class Solution {
public:
    int getSum(int num)
    {
        int sum=0;
        while(num>0)
        {
            int digit=num%10;
            sum+=digit;
            num=num/10;
        }
        return sum;
    }
    int getLucky(string s, int k) {
        int sum=0;
        string digits="";
        char ch;
        for(int i=0;i<s.length();i++)
        {
            digits+=to_string(s[i]-'a'+1);
        }
        int ans=0;
        for(auto ch:digits)
        {
            ans=ans+(ch-'0');
        }

        k--;
        while(k>0)
        {
            ans = getSum(ans);
            k--;
        }
        return ans;
    }
};