class Solution {
private:
    void mark(vector<vector<int>>& copyGrid,int i,int j,int rows,int cols)
    {
        copyGrid[i][j]=0;
        if(i>0 && copyGrid[i-1][j]==1) mark(copyGrid,i-1,j,rows,cols);
        if(i<rows-1 && copyGrid[i+1][j]==1) mark(copyGrid,i+1,j,rows,cols);
        if(j>0 && copyGrid[i][j-1]==1) mark(copyGrid,i,j-1,rows,cols);
        if(j<cols-1 && copyGrid[i][j+1]==1) mark(copyGrid,i,j+1,rows,cols);
    }
    int countIslands(vector<vector<int>> grid)
    {
        int noOfRows=grid.size();
        int noOfCols=grid[0].size();
        int noOfIslands=0;
        for(int i=0;i<noOfRows;i++)
        {
            for(int j=0;j<noOfCols;j++)
            {
                if(grid[i][j]==0) continue;
                noOfIslands++;
                mark(grid,i,j,noOfRows,noOfCols);
            }
        }
        return noOfIslands;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        int noOfRows=grid.size();
        int noOfCols=grid[0].size();
        int noOfIslands=countIslands(grid);
        if(noOfIslands!=1) return 0;

        for(int i=0;i<noOfRows;i++)
        {
            for(int j=0;j<noOfCols;j++)
            {
                if(grid[i][j]==0) continue;
                grid[i][j]=0;
                noOfIslands=countIslands(grid);
                if(noOfIslands!=1) return 1;
                grid[i][j]=1;
            }
        }
        return 2;
    }
};