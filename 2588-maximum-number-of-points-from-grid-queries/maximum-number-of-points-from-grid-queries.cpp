class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();
        int k = queries.size();
        vector<int> answer(k, 0);
        vector<pair<int, int>> sortedQueries(k);
        for (int i = 0; i < k; i++) {
            sortedQueries[i] = {queries[i], i};
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        int points = 0;
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            minHeap;
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> visited(m, vector<int>(n, 0));
        minHeap.push({grid[0][0], {0, 0}});
        visited[0][0] = 1;
        for (auto [queryValue, index] : sortedQueries) {
            while (!minHeap.empty() && minHeap.top().first < queryValue) {
                points++;
                auto [cellVal, position] = minHeap.top();
                minHeap.pop();
                int curX = position.first;
                int curY = position.second;
                for (auto [dx, dy] : dir) {
                    int newX = curX + dx, newY = curY + dy;
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n &&
                        !visited[newX][newY]) {
                        minHeap.push({grid[newX][newY], {newX, newY}});
                        visited[newX][newY] = 1;
                    }
                }
            }
            answer[index] = points;
        }
        return answer;
    }
};