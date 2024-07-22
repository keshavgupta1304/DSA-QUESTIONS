class Solution {
private:
    void solve(int index,string digits,vector<string>& ans,string output,string mapping[])
    {
        if(index>=digits.size())
        {
            ans.push_back(output);
            return;
        }
        int number=digits[index]-'0';
        string value=mapping[number];
        for(int i=0;i<value.length();i++)
        {
            output.push_back(value[i]);
            solve(index+1,digits,ans,output,mapping);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)
        {
            return {};
        }
        int index=0;
        vector<string> ans; 
        string output;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(index,digits,ans,output,mapping);
        return ans;
    }
};