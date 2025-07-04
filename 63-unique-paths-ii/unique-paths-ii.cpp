class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<int> prev(m, 0);
        for (int i = 0; i < n; i++) {
            vector<int> cur(m,0);
            for (int j = 0; j < m; j++) {
                if(!obstacleGrid[i][j])
                {
                    if(i==0 && j==0) cur[j]=1;
                    else
                    {
                        int left=0;
                        int up=0;
                        if(i>0) up=prev[j];
                        if(j>0) left=cur[j-1];
                        cur[j]=up+left;
                    }
                }
            }
            prev=cur;
        }
        return prev[m - 1];
    }
};