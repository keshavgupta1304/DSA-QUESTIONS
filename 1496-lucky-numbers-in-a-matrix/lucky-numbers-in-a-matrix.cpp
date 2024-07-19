class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int maxOfRowMin=INT_MIN;
        for(int i=0;i<rows;i++)
        {
            int rowMinimum=INT_MAX;
            for(int j=0;j<cols;j++)
            {
                rowMinimum=min(rowMinimum,matrix[i][j]);
            }
            maxOfRowMin=max(maxOfRowMin,rowMinimum);
        }
        int minOfColMax=INT_MAX;
        for(int i=0;i<cols;i++)
        {
            int colMaximum=INT_MIN;
            for(int j=0;j<rows;j++)
            {
                colMaximum=max(colMaximum,matrix[j][i]);
            }
            minOfColMax=min(minOfColMax,colMaximum);
        }
        vector<int> ans;
        if(minOfColMax==maxOfRowMin)
        {
            return {maxOfRowMin};
        }
        return {};
    }
};