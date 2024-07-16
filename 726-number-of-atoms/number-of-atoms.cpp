class Solution {
public:
    string countOfAtoms(string formula) {
        stack<unordered_map<string, int>> finalCount;
        finalCount.push(unordered_map<string, int>());
        int index=0;
        while(index<formula.size())
        {
            if(formula[index]=='(')
            {
                finalCount.push(unordered_map<string, int>());
                index++;
            }
            else if(formula[index]==')')
            {
                unordered_map<string,int> currParenthesis=finalCount.top();
                finalCount.pop();
                index++;
                string multiplier;
                while(index<formula.size() && isdigit(formula[index]))
                {
                    multiplier+=formula[index];
                    index++;
                }
                if(!multiplier.empty())
                {
                    int mult=stoi(multiplier);
                    for(auto& [atom,count]:currParenthesis)
                    {
                        currParenthesis[atom]=count*mult;
                    }
                }
                for(auto& [atom,count]:currParenthesis)
                {
                    finalCount.top()[atom]+=count;
                }
            }
            else
            {
                string currAtom;
                string currCount;
                currAtom+=formula[index];
                index++;
                while(index<formula.length() && islower(formula[index]))
                {
                    currAtom+=formula[index];
                    index++;
                }
                while(index<formula.length() && isdigit(formula[index]))
                {
                    currCount+=formula[index];
                    index++;
                }
                int count=currCount.empty()?1:stoi(currCount);
                finalCount.top()[currAtom]+=count;
            }
        }
        map<string, int> final(finalCount.top().begin(),finalCount.top().end());
        string result;
        for(auto& [atom,count]:final)
        {
            result+=atom;
            if(count>1)
            {
                result+=to_string(count);
            }
        }
        return result;
    }
};