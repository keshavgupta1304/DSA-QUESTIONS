class Solution {
    int directions[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    bool isLand(int i,int j,vector<vector<int>>& grid)
    {
        return grid[i][j] == 1;
    }
public:
    
    bool isSubIsland(int i,int j,vector<vector<int>>& grid1, vector<vector<int>>& grid2,
    vector<vector<bool>>& visited)
    {
        int totalRowsInGrid2=grid2.size();
        int totalColsInGrid2=grid2[0].size();

        queue<pair<int,int>> queue;
        queue.push({i,j});
        visited[i][j] = true;
        bool isSub = true;
        while(!queue.empty())
        {
            int curr_i = queue.front().first;
            int curr_j = queue.front().second;
            queue.pop();
            if(!isLand(curr_i,curr_j,grid1)) isSub = false;
            for(auto& direction:directions)
            {
                int next_i = curr_i + direction[0];
                int next_j = curr_j + direction[1];
                if(next_i>=0 && next_i<totalRowsInGrid2 && next_j>=0 && next_j<totalColsInGrid2 &&
                !visited[next_i][next_j] && isLand(next_i,next_j,grid2))
                {
                    queue.push({next_i,next_j});
                    visited[next_i][next_j]=true;
                }
            }
        }
        return isSub;

    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int rows=grid2.size();
        int cols=grid2[0].size();
        int ans=0;
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(!visited[i][j] && isLand(i,j,grid2) && isSubIsland(i,j,grid1,grid2,visited))
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};