class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<int> minValueInRow(rows,INT_MAX);
        vector<int> minValueInCol(cols,0);
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                minValueInRow[i]=min(minValueInRow[i],matrix[i][j]);
                minValueInCol[j]=max(minValueInCol[j],matrix[i][j]);
            }
        }
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(matrix[i][j] == minValueInRow[i] && matrix[i][j] == minValueInCol[j])
                {
                    vector<int> ans;
                    ans.push_back(matrix[i][j]);
                    return ans;
                }
            }
        }
        return {};


    }
};