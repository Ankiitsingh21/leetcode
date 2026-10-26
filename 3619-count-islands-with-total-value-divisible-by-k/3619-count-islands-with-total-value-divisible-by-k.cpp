class Solution {
    long long dfs(vector<vector<int>>& grid,
                  vector<vector<int>>& vis,
                  int row,
                  int col) {

        vis[row][col] = 1;

        int n = grid.size();
        int m = grid[0].size();

        int nrow[4] = {-1, 1, 0, 0};
        int ncol[4] = {0, 0, -1, 1};

        long long sum = grid[row][col];

        for (int i = 0; i < 4; i++) {

            int nnr = row + nrow[i];
            int nnc = col + ncol[i];

            if (nnr >= 0 && nnr < n &&
                nnc >= 0 && nnc < m &&
                grid[nnr][nnc] != 0 &&
                !vis[nnr][nnc]) {

                sum += dfs(grid, vis, nnr, nnc);
            }
        }

        return sum;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] != 0 && !vis[i][j]) {

                    long long sum = dfs(grid, vis, i, j);

                    if (sum % k == 0) {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};