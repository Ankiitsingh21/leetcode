class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(grid.size(),
                                 vector<int>(grid[0].size(), INT_MAX));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        pq.push({grid[0][0], {0, 0}});
        while (!pq.empty()) {
            int cost = pq.top().first;
            auto [row, col] = pq.top().second;
            pq.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int newDist = cost + grid[nrow][ncol];
                    if (newDist < dist[nrow][ncol]) {
                        dist[nrow][ncol] = newDist;
                        pq.push({newDist, {nrow, ncol}});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};