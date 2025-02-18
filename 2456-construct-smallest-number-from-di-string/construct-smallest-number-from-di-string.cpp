class Solution {
public:
    string smallestNumber(string pattern) {
        int n=pattern.size();
        stack<int> stk;
        string result="";
        for(int i=0;i<=n;i++)
        {
            stk.push(i+1);
            if(pattern[i]=='I' || i==n)
            {
                while(!stk.empty())
                {
                    result+=to_string(stk.top());
                    stk.pop();
                }
            }
        }
        return result;
    }
};