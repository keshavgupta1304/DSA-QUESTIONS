class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> prev(n,INT_MAX);
        for(int i=0;i<m;i++)
        {
            vector<int> cur(n,0);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0) cur[j]=grid[i][j];
                else
                {
                    int up=INT_MAX,left=INT_MAX;
                    if(i>0) up=prev[j];
                    if(j>0) left=cur[j-1];
                    cur[j]=grid[i][j]+min(up,left);
                }
            }
            prev=cur;
        }
        return prev[n-1];
    }
};