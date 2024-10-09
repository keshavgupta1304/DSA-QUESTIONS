class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        int unbalanced=0;
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            if(ch=='(')
            {
                stk.push(ch);
            }
            else
            {
                if(stk.empty())
                {
                    unbalanced++;
                }
                else
                {
                    stk.pop();
                }
            }
        }
        return stk.size()+unbalanced;
    }
};