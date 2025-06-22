class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        for(int i=0;i<s.size();i+=k)
        {
            result.push_back(s.substr(i,k));
        }
        result.back()+=string(k-result.back().size(),fill);
        return result;
    }
};