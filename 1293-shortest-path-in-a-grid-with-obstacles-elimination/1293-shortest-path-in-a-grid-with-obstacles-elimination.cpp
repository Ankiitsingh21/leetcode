class Solution {
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    int dfs(int row, int col, vector<vector<int>>& grid, int k,
            vector<vector<int>>& vis, vector<vector<vector<int>>>& dp) {
        if (row == grid.size() - 1 && col == grid[0].size() - 1) {
            return 0;
        }
        if (dp[row][col][k] != -1)
            return dp[row][col][k];
        int ans = INT_MAX;
        for (int i = 0; i < 4; i++) {
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            int cnt = INT_MAX;
            if (nrow >= 0 && nrow < grid.size() && ncol >= 0 &&
                ncol < grid[0].size() && !vis[nrow][ncol] &&
                grid[nrow][ncol] == 0) {
                vis[nrow][ncol] = 1;
                int cost = dfs(nrow, ncol, grid, k, vis, dp);
                if (cost != -1) {
                    cnt = cost + 1;
                }
                vis[nrow][ncol] = 0;

                // vis[nrow]
            } else if (nrow >= 0 && nrow < grid.size() && ncol >= 0 &&
                       ncol < grid[0].size() && !vis[nrow][ncol] &&
                       grid[nrow][ncol] == 1 && k > 0) {
                vis[nrow][ncol] = 1;
                int cost = dfs(nrow, ncol, grid, k - 1, vis, dp);
                if (cost != -1) {
                    cnt = cost + 1;
                }
                vis[nrow][ncol] = 0;
            }
            ans = min(ans, cnt);
        }
        // if(ans==INT_MAX) {}
        return dp[row][col][k] = ans == INT_MAX ? -1 : ans;
    }

public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        // vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        // vis[0][0] = 1;
        // vector<vector<vector<int>>>
        // dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(k+1,-1)));
        // return dfs(0, 0, grid, k, vis,dp);
        vector<vector<vector<int>>> vis(
            grid.size(),
            vector<vector<int>>(grid[0].size(), vector<int>(k + 1, 0)));
        queue<tuple<int, int, int, int>> q;
       q.emplace(0,0,k,0);
        vis[0][0][k] = 1;
        // int ans=INT_MAX;
        while (!q.empty()) {
            auto [row,col,rem,steps]=q.front();
            q.pop();
            if(row==grid.size()-1 && col==grid[0].size()-1) return steps;
            for (int i = 0; i < 4; i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                // int cnt = INT_MAX;
                if (nrow >= 0 && nrow < grid.size() && ncol >= 0 &&
                    ncol < grid[0].size() && !vis[nrow][ncol][rem] &&
                    grid[nrow][ncol] == 0) {
                    vis[nrow][ncol][rem] = 1;
                    q.emplace(nrow,ncol,rem,steps+1);
                    // vis[nrow][ncol][rem] = 0;

                    // vis[nrow]
                } else if (nrow >= 0 && nrow < grid.size() && ncol >= 0 &&
                           ncol < grid[0].size() && 
                           grid[nrow][ncol] == 1 && rem > 0 && !vis[nrow][ncol][rem-1]) {
                    vis[nrow][ncol][rem-1] = 1;
                    q.emplace(nrow,ncol,rem-1,steps+1);
                    // q.push({{nrow,ncol},rem-1});
                    // vis[nrow][ncol][rem-1] = 0;
                }
                // ans = min(ans, cnt);
            }
        }
        return -1;
    }
};