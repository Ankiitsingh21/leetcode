class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        // Destination when entering a cell from the left or above.
        // Store destination as flattened index: x * n + y.
        // -1 means invalid path.

        vector<vector<int>> destRight(m, vector<int>(n, -1));
        vector<vector<int>> destDown(m, vector<int>(n, -1));

        // Precompute reflection destinations.
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                int id = i * n + j;

                if (grid[i][j] == 0) {
                    destRight[i][j] = id;
                    destDown[i][j] = id;
                }
                else {
                    // Entering mirror while moving right:
                    // Reflect down.
                    if (i + 1 < m) {
                        destRight[i][j] = destDown[i + 1][j];
                    }

                    // Entering mirror while moving down:
                    // Reflect right.
                    if (j + 1 < n) {
                        destDown[i][j] = destRight[i][j + 1];
                    }
                }
            }
        }

        // DP: number of ways to reach each empty cell.
        vector<vector<long long>> dp(m, vector<long long>(n, 0));

        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (dp[i][j] == 0) continue;

                long long ways = dp[i][j];

                // Try moving right.
                if (j + 1 < n) {
                    int id = destRight[i][j + 1];

                    if (id != -1) {
                        int x = id / n;
                        int y = id % n;

                        dp[x][y] = (dp[x][y] + ways) % MOD;
                    }
                }

                // Try moving down.
                if (i + 1 < m) {
                    int id = destDown[i + 1][j];

                    if (id != -1) {
                        int x = id / n;
                        int y = id % n;

                        dp[x][y] = (dp[x][y] + ways) % MOD;
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};