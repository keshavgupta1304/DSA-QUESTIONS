class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int noOfRows=rowSum.size();
        int noOfCols=colSum.size();
        vector<vector<int>> matrix(noOfRows,vector<int>(noOfCols));
        for(int i=0;i<noOfRows;i++)
        {
            for(int j=0;j<noOfCols;j++)
            {
                matrix[i][j]=min(rowSum[i],colSum[j]);
                rowSum[i]-=matrix[i][j];
                colSum[j]-=matrix[i][j];
            }
        }
        return matrix;
    }
};