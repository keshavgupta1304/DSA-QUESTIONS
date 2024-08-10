class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        int ans=0;
        vector<vector<int>> expandedGrid(n*3,vector<int>(n*3,1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int startRow=i*3;
                int startCol=j*3;
                if(grid[i][j]=='/')
                {
                    expandedGrid[startRow][startCol+2]=0;
                    expandedGrid[startRow+1][startCol+1]=0;
                    expandedGrid[startRow+2][startCol]=0;
                }
                else if(grid[i][j]=='\\')
                {
                    expandedGrid[startRow][startCol]=0;
                    expandedGrid[startRow+1][startCol+1]=0;
                    expandedGrid[startRow+2][startCol+2]=0;
                }
            }
        }
        for(int i=0;i<n*3;i++)
        {
            for(int j=0;j<n*3;j++)
            {
                if(expandedGrid[i][j]==0) continue;
                ans++;
                markPath(expandedGrid,i,j,n);
            }
        }
        return ans;
    }
    void markPath(vector<vector<int>>& expandedGrid,int i,int j,int n)
    {
        expandedGrid[i][j]=0;
        if(i>0 && expandedGrid[i-1][j]==1) markPath(expandedGrid,i-1,j,n);
        if(i<((n*3)-1) && expandedGrid[i+1][j]==1) markPath(expandedGrid,i+1,j,n);
        if(j>0 && expandedGrid[i][j-1]==1) markPath(expandedGrid,i,j-1,n);
        if(j<((n*3)-1) && expandedGrid[i][j+1]==1) markPath(expandedGrid,i,j+1,n);
    }
};