class Solution {
public:
    void generate(int closeCount,int openCount,int n,string s,vector<string> &result)
    {
        if(closeCount==openCount && closeCount+openCount==2*n)
        {
            result.push_back(s);
            return;
        }
        if(openCount < n)
        {
            generate(closeCount,openCount+1,n,s+'(',result);
        }
        if(closeCount<openCount)
        {
            generate(closeCount+1,openCount,n,s+')',result);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s="";
        generate(0,0,n,s,result);
        return result;
    }
};