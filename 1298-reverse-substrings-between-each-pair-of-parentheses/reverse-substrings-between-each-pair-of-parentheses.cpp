class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.length();
        stack<int> opened;
        vector<int> matching(n);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                opened.push(i);
            }
            if(s[i]==')')
            {
                int j = opened.top();
                opened.pop();
                matching[i]=j;
                matching[j]=i;
            }
        }
        string result;
        for(int index=0,direction=1;index<n;index=index+direction)
        {
            if(s[index]=='(' || s[index]==')')
            {
                index=matching[index];
                direction=-direction;
            }
            else
            {
                result+=s[index];
            }
        }
        return result;

    }
};