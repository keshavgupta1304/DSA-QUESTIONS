class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto query:queries)
        {
            int left=query[0];
            int right=query[1];
            int result=0;
            for(int i=left;i<=right;i++)
            {
                result=result^arr[i];
            }
            ans.push_back(result);
        }
        return ans;
    }
};