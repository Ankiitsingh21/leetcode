class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        long long ans = LLONG_MIN;

        // single cell
        for (int i = 1; i < m - 1; i++) {

            for (int j = 1; j < n - 1; j++) {

                ans = max(ans, (long long)grid[i][j]);
            }
        }

        // row wise
        for (int i = 0; i < m; i++) {

            vector<long long> prefix(n + 1, 0);

            for (int j = 0; j < n; j++) {

                prefix[j + 1] = prefix[j] + grid[i][j];
            }

            long long mini = 0;

            for (int r = 2; r <= n; r++) {

                mini = min(mini, prefix[r - 2]);

                ans = max(ans, prefix[r] - mini);
            }
        }

        // column wise
        for (int j = 0; j < n; j++) {

            vector<long long> prefix(m + 1, 0);

            for (int i = 0; i < m; i++) {

                prefix[i + 1] = prefix[i] + grid[i][j];
            }

            long long mini = 0;

            for (int r = 2; r <= m; r++) {

                mini = min(mini, prefix[r - 2]);

                ans = max(ans, prefix[r] - mini);
            }
        }

        return (int)ans;
    }
};