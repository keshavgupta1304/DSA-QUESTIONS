class Solution {
public:
    void markLand(vector<vector<char>>& grid,int i,int j,int rows,int cols)
    {
        grid[i][j]='0';
        if(i>0 && grid[i-1][j]=='1') markLand(grid,i-1,j,rows,cols);
        if(i<rows-1 && grid[i+1][j]=='1') markLand(grid,i+1,j,rows,cols);    
        if(j>0 && grid[i][j-1]=='1') markLand(grid,i,j-1,rows,cols);    
        if(j<cols-1 && grid[i][j+1]=='1') markLand(grid,i,j+1,rows,cols);    
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int res=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]=='0') continue;
                res++;
                markLand(grid,i,j,rows,cols);
            }
        }
        return res;

    }
};