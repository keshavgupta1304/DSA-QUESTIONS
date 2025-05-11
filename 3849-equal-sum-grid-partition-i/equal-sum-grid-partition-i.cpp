class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long totSum=0;
        int rows=grid.size();
        int cols=grid[0].size();
        for(int row=0;row<rows;row++)
        {
            for(int col=0;col<cols;col++)
            {
                totSum+=grid[row][col];
            }
        }
        if(totSum&1) return false;
        long long rowSum=0;
        for(int i=0;i<rows-1;i++)
        {
            for(int j=0;j<cols;j++)
            {
                rowSum+=grid[i][j];
            }
            if(rowSum*2==totSum) return true;
        }
        long long colSum=0;
        for(int i=0;i<cols-1;i++)
        {
            for(int j=0;j<rows;j++)
            {
                colSum+=grid[j][i];
            }
            if(colSum*2==totSum) return true;
        }
        return false;
    }
};