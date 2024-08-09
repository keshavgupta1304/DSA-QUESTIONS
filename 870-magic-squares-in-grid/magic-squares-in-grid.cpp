class Solution {
private:
    bool solve(int startRow,int startCol,vector<vector<int>> grid)
    {
        bool visited[10]={false};
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                int num=grid[i+startRow][j+startCol];
                if(num<1 || num>9) return false;
                if(visited[num]) return false;
                visited[num]=true;
            }
        }
        int diagonalSum1=grid[startRow][startCol]+grid[startRow+1][startCol+1]+grid[startRow+2][startCol+2];
        int diagonalSum2=grid[startRow][startCol+2]+grid[startRow+1][startCol+1]+grid[startRow+2][startCol];

        if(diagonalSum1!=diagonalSum2) return false;

        int rowSum1=grid[startRow][startCol]+grid[startRow][startCol+1]+grid[startRow][startCol+2];
        int rowSum2=grid[startRow+1][startCol]+grid[startRow+1][startCol+1]+grid[startRow+1][startCol+2];
        int rowSum3=grid[startRow+2][startCol]+grid[startRow+2][startCol+1]+grid[startRow+2][startCol+2];

        if(!(rowSum1==diagonalSum1 && rowSum2==diagonalSum1 && rowSum3==diagonalSum1))
        {
            return false;
        }
        
        int colSum1=grid[startRow][startCol]+grid[startRow+1][startCol]+grid[startRow+2][startCol];
        int colSum2=grid[startRow][startCol+1]+grid[startRow+1][startCol+1]+grid[startRow+2][startCol+1];
        int colSum3=grid[startRow][startCol+2]+grid[startRow+1][startCol+2]+grid[startRow+2][startCol+2];       
        
        if(!(colSum1==diagonalSum1 && colSum2==diagonalSum1 && colSum3==diagonalSum1))
        {
            return false;
        }

        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans=0;
        int total_rows=grid.size();
        int total_cols=grid[0].size();
        if(total_rows<3 || total_cols<3)
        {
            return 0;
        }
        for(int row=0;row<total_rows-2;row++)
        {
            for(int col=0;col<total_cols-2;col++)
            {
                if(solve(row,col,grid)) ans++;
            }
        }
        return ans;
    }
};