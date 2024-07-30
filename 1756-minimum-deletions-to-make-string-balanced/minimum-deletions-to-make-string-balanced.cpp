class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.length();
        int ans=0;
        if(n==1)
        {
            return ans;
        }
        stack<char> stack;
        int i=0;
        
        while(i<n)
        {
            if(!stack.empty() && stack.top()=='b' && s[i]=='a')
            {
                stack.pop();
                ans++;
            }
            else
            {
                stack.push(s[i]);
            }
            i++;
        }
           
        return ans;
    }
};