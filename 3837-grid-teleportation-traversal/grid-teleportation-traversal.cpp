class Solution {
public:
    using pii = pair<int, int>;
    using pipii = pair<int, pii>;

    int minMoves(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        unordered_map<char, vector<pii>> portals;
        unordered_set<char> used;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (isupper(grid[i][j]))
                    portals[grid[i][j]].push_back({i, j});

        priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        vector<pii> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!pq.empty()) {
            auto [steps, pos] = pq.top(); pq.pop();
            int x = pos.first, y = pos.second;

            if (x == m - 1 && y == n - 1)
                return steps;
            if (steps > dist[x][y]) continue;
            for (auto& [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if (grid[nx][ny] == '#') continue;
                if (steps + 1 < dist[nx][ny]) {
                    dist[nx][ny] = steps + 1;
                    pq.push({steps + 1, {nx, ny}});
                }
            }
            char cell = grid[x][y];
            if (isupper(cell) && !used.count(cell)) {
                used.insert(cell);
                for (auto& [tx, ty] : portals[cell]) {
                    if (steps < dist[tx][ty]) {
                        dist[tx][ty] = steps;
                        pq.push({steps, {tx, ty}});
                    }
                }
            }
        }
        return -1;
    }
};
