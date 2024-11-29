class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dir = {
            {-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // up,right,down,left
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0}); // time,row,col

        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            int time = current[0];
            int row = current[1];
            int col = current[2];
            if (row == rows - 1 && col == cols - 1)
                return time;
            if (visited[row][col])
                continue;
            visited[row][col]=true;
            for(auto directions:dir)
            {
                int nextRow = row + directions[0];
                int nextCol = col + directions[1];
                if (nextRow < rows && nextCol < cols && nextRow >= 0 &&
                    nextCol >= 0 && !visited[nextRow][nextCol]) {
                        int waitTime=((grid[nextRow][nextCol]-time)%2)==0?1:0;
                        int nextTime=max(grid[nextRow][nextCol]+waitTime,time+1);
                        pq.push({nextTime,nextRow,nextCol});
                }
                continue;
            }
        }
        return -1;
    }
};