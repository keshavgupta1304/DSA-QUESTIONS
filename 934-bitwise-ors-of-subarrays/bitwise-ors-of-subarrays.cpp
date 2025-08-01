class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;
        unordered_set<int> curr;
        curr.insert(0);
        for (auto num : arr) {
            unordered_set<int> curr2;
            for(auto ele:curr)
            {
                curr2.insert(ele|num);
            }
            curr2.insert(num);
            curr=curr2;
            for(auto x:curr) ans.insert(x);
        }
        return (int)ans.size();
    }
};