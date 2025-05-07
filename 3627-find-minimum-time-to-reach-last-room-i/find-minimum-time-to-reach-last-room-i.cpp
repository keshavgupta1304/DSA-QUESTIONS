class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> timeTaken(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        minHeap.push({0, {0, 0}});
        timeTaken[0][0] = 0; 
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        while (!minHeap.empty()) {
            auto current = minHeap.top();
            minHeap.pop();
            int currentTime = current.first;
            int row = current.second.first;
            int col = current.second.second;
            
            if (row == n - 1 && col == m - 1) {
                return currentTime;
            }
            
            for (auto d : dir) {
                int newRow = row + d[0];
                int newCol = col + d[1];
                
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                    int newTime = max(currentTime + 1, moveTime[newRow][newCol]+1);
                    
                    if (newTime < timeTaken[newRow][newCol]) {
                        timeTaken[newRow][newCol] = newTime;
                        minHeap.push({newTime, {newRow, newCol}});
                    }
                }
            }
        }
        
        return -1;
    }
};
