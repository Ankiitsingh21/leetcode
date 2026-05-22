class Solution {
    int solve(int index, int lastIndex, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {
        if (index == grid.size())
            return 0;
        if (dp[index][lastIndex + 1] != -1)
            return dp[index][lastIndex + 1];
        int ans = INT_MAX;
        for (int i = 0; i < grid[index].size(); i++) {
            if (i == lastIndex)
                continue;
            ans = min(ans, grid[index][i] + solve(index + 1, i, grid, dp));
        }
        return dp[index][lastIndex + 1] = ans;
    }

public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size() + 1,
                               vector<int>(grid[0].size() + 1, 0));
        // return solve(0,-1,grid,dp);
        int n = grid.size();

        // vector<vector<int>> dp(n, vector<int>(n, 0));

        // first row
        // for (int lastIndex = 0; lastIndex <= n; lastIndex++) {
        //     dp[n][lastIndex] = 0;
        // }

        // bottom-up
        for (int index = n - 1; index >= 0; index--) {

            for (int lastIndex = -1; lastIndex < n; lastIndex++) {

                int ans = INT_MAX;

                for (int i = 0; i < n; i++) {

                    if (i == lastIndex)
                        continue;

                    ans = min(ans, grid[index][i] + dp[index + 1][i + 1]);
                }

                dp[index][lastIndex + 1] = ans;
            }
        }

        return dp[0][0];
    }
};
