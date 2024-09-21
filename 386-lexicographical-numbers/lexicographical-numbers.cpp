class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        vector<string> ordering;
        for(int i=1;i<=n;i++)
        {
            ordering.push_back(to_string(i));
        }
        sort(ordering.begin(),ordering.end(),[&](const string&a,const string&b){
            return a<b;
        });
        for(auto stringNum:ordering)
        {
            ans.push_back(stoi(stringNum));
        }
        return ans;
    }
};