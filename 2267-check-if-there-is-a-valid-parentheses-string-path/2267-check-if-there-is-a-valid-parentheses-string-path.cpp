class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int len = m + n - 1;

        // A valid parentheses string must have even length
        if (len % 2 == 1)
            return false;

        // Must start with '(' and end with ')'
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        // dp[i][j][bal] = can we reach (i,j) with balance = bal?
        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(len + 1, false))
        );

        // Starting cell
        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Skip starting cell
                if (i == 0 && j == 0)
                    continue;

                int change = (grid[i][j] == '(' ? 1 : -1);

                for (int bal = 0; bal <= len; bal++) {

                    int prevBal = bal - change;

                    if (prevBal < 0 || prevBal > len)
                        continue;

                    // From top
                    if (i > 0 && dp[i - 1][j][prevBal]) {
                        dp[i][j][bal] = true;
                    }

                    // From left
                    if (j > 0 && dp[i][j - 1][prevBal]) {
                        dp[i][j][bal] = true;
                    }
                }
            }
        }

        // Valid string must end with balance 0
        return dp[m - 1][n - 1][0];
    }
};