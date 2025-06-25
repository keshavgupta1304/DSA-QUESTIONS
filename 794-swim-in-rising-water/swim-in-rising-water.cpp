class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int ans = INT_MIN;
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minheap;
        minheap.push({grid[0][0], 0, 0});
        
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        while (!minheap.empty()) {
            auto [x, row, col] = minheap.top();
            minheap.pop();
            
            if (visited[row][col]) continue;
            visited[row][col] = true;
            ans = max(ans, x);
            
            if (row == n - 1 && col == n - 1)
                return ans;
            
            for (auto d : dir) {
                int newrow = row + d.first;
                int newcol = col + d.second;
                
                if (newrow >= 0 && newcol >= 0 && newrow < n && newcol < n && !visited[newrow][newcol]) {
                    minheap.push({grid[newrow][newcol], newrow, newcol});
                }
            }
        }
        return -1;
    }
};