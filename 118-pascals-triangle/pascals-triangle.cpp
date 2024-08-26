class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0]={1};
        for(int i=1;i<numRows;i++)
        {
            vector<int> element(i+1);
            element[0]=1;
            element[i]=1;
            for(int j=1;j<element.size()-1;j++)
            {
                element[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans[i]=element;
        }
        return ans;
    }
};