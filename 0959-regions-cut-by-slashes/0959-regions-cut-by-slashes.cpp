class Solution {
    void solve(int i, int j, vector<vector<int>>& arr,
               vector<vector<int>>& vis) {
        // cout<<i<<" ";
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if (nrow >= 0 && nrow < arr.size() && ncol >= 0 &&
                    ncol < arr[i].size() && arr[nrow][ncol] == 0 &&
                    !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        return;
    }

public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> arr(n * 3, vector<int>(m * 3, 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                char c = grid[i][j];
                if (c != '\\' && c != '/')
                    continue;

                int startingRow = i * 3;
                int startingCol = j * 3;
                if (c == '\\') {
                    for (int i = 0; i < 3; i++) {
                        arr[startingRow][startingCol] = 1;
                        startingRow++;
                        startingCol++;
                    }
                }
                if (c == '/') {
                    int endingRow = startingRow;
                    int endingCol = startingCol + 2;
                    for (int i = 0; i < 3; i++) {
                        arr[endingRow][endingCol] = 1;
                        endingRow++;
                        endingCol--;
                    }
                }
            }
        }
        // for (int i = 0; i < arr.size(); i++) {
        //     for (int j = 0; j < arr[i].size(); j++) {
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        vector<vector<int>> vis(arr.size(), vector<int>(arr.size(), 0));

        int cnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr[i].size(); j++) {
                if (arr[i][j] == 0 && !vis[i][j]) {
                    //  cout<<arr[i][j]<<" "<<vis[i][j]<<" "<<endl;;
                    cnt++;
                    solve(i, j, arr, vis);
                }
            }
        }
        return cnt;
    }
};