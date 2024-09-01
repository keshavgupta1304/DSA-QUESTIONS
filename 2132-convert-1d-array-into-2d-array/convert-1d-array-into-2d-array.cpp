class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        long long elements=m*n;
        if(original.size()!=elements)
        {
            return {};
        }
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                long long index=i*n+j;
                ans[i][j] = original[index];
            }
        }
        return ans;
    }
};