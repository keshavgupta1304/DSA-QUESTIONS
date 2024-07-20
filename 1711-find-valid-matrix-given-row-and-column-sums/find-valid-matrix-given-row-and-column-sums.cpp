class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int noOfRows=rowSum.size();
        int noOfCols=colSum.size();
        vector<int> currRowSum(noOfRows,0);
        vector<int> currColSum(noOfCols,0);
        vector<vector<int>> matrix(noOfRows,vector<int>(noOfCols));
        for(int i=0;i<noOfRows;i++)
        {
            for(int j=0;j<noOfCols;j++)
            {
                matrix[i][j]=min(rowSum[i]-currRowSum[i],colSum[j]-currColSum[j]);
                currRowSum[i]+=matrix[i][j];
                currColSum[j]+=matrix[i][j];

            }
        }
        return matrix;
    }
};