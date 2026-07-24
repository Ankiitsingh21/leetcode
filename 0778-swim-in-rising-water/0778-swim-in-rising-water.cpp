class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
         int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = grid[0][0];

        // NORMAL QUEUE storing (diff, row, col)
        // queue<pair<int, pair<int,int>>> q;
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<>
        > q;
        q.push({grid[0][0], {0, 0}});

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            int row = q.top().second.first;
            int col = q.top().second.second;
            int diff = q.top().first;
            q.pop();
            if (diff > dist[row][col]) continue;
            // if (row == n - 1 && col == n - 1) return diff;
            for (int i = 0; i < 4; i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    // int newDiff = abs(grid[nrow][ncol] - grid[row][col]);
                    int newDiff = max(diff, grid[nrow][ncol]);

                    if (newDiff < dist[nrow][ncol]) {
                        dist[nrow][ncol] = newDiff;
                        q.push({newDiff, {nrow, ncol}});
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};