class Solution {
public:
    int minCost(vector<vector<int>> grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dist(n,vector<vector<int>>(m,vector<int>(k + 1,INT_MAX)));
        
        vector<pair<int,pair<int,int>>> vals;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                vals.push_back({grid[i][j],{i,j}});
            }
        }

        sort(vals.begin(), vals.end());

        vector<vector<int>> pos(n,vector<int>(m));

        vector<vector<int>> sortedDist(k + 1, vector<int>(n * m));
        vector<vector<int>> prefixMin(k + 1, vector<int>(n * m));

        for(int i = 0; i < n*m; i++) {
            pos[vals[i].second.first][vals[i].second.second] = i;
        }
        
        for(int nums = k; nums >= 0; nums--) {
            if(nums != k) {
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < m; j++) {
                        auto it = upper_bound(vals.begin(),vals.end(), make_pair(grid[i][j], make_pair(n,m)));
                        dist[i][j][nums] = min(dist[i][j][nums], prefixMin[nums+1][it - vals.begin() - 1]);
                    }
                }
            }
            dist[n-1][m-1][nums] = 0;
            for(int i = n-1; i >= 0; i--) {
                for(int j = m-1; j >= 0; j--) {
                    if(i != 0) {
                        dist[i-1][j][nums] = min(dist[i-1][j][nums], dist[i][j][nums] + grid[i][j]);
                    }
                    if(j != 0) {
                        dist[i][j - 1][nums] = min(dist[i][j - 1][nums], dist[i][j][nums] + grid[i][j]);
                    }
                }
            }
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    sortedDist[nums][pos[i][j]] = dist[i][j][nums];
                }
            }
            prefixMin[nums][0] = sortedDist[nums][0];
            for(int i = 1; i < n*m; i++) {
                prefixMin[nums][i] = min(prefixMin[nums][i-1], sortedDist[nums][i]);
            }
        }

        return dist[0][0][0];
    }
};