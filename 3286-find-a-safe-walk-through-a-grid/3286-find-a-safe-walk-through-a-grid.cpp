class Solution {
    bool solve(int r, int c, vector<vector<int>>& arr, int health,
               vector<vector<bool>>& vis, vector<vector<int>>& best) {

        if (health <= 0)
            return false;
        if (r == arr.size() - 1 && c == arr[0].size() - 1)
            return true;
        // bool pick=false;

        if (best[r][c] >= health)
            return false;

        best[r][c] = health;

        int nrow[4] = {-1, 0, 1, 0};
        int ncol[4] = {0, 1, 0, -1};
        bool ans = false;
        for (int i = 0; i < 4; i++) {
            int row = r + nrow[i];
            int col = c + ncol[i];

            if (row >= 0 && row < arr.size() && col >= 0 &&
                col < arr[0].size() && !vis[row][col]) {
                vis[row][col] = 1;
                if (arr[row][col] == 0) {
                    // pick=true;
                    if (solve(row, col, arr, health, vis, best)) {

                        ans = true;
                        break;
                    }
                } else {
                    // vis[ro]
                    if (solve(row, col, arr, health - 1, vis, best)) {

                        ans = true;
                        break;
                    }
                }
                vis[row][col] = 0;
            }
        }
        return ans;
    }

public:
    bool findSafeWalk(vector<vector<int>>& arr, int h) {
        // vector<vector<bool>> vis(arr.size(),
        //                          vector<bool>(arr[0].size(), false));
        // if (arr[0][0] == 1)
        //     health = health - 1;

        // vis[0][0] = true;
        // vector<vector<int>> best(arr.size(), vector<int>(arr[0].size(), -1));
        // return solve(0, 0, arr, health, vis, best);
        queue<tuple<int, int, int>> q;
        // vis[0, 0] = true;
        vector<vector<int>> best(arr.size(), vector<int>(arr[0].size(), -1));
        if (arr[0][0] == 1)
            h = h - 1;
        if (h <= 0)
            return false;
        q.push({0, 0, h});
        best[0][0] = h;
        int nrow[4] = {-1, 0, 1, 0};
        int ncol[4] = {0, 1, 0, -1};
        while (!q.empty()) {
            auto [r, c, health] = q.front();
            q.pop();
            if (r == arr.size() - 1 && c == arr[0].size() - 1)
                return true;
            for (int i = 0; i < 4; i++) {
                int row = r + nrow[i];
                int col = c + ncol[i];
                if (row >= 0 && row < arr.size() && col >= 0 &&
                    col < arr[0].size()) {
                    // vis[row][col]=1;
                    int newHealth = health - arr[row][col];
                    if (newHealth <= 0)
                        continue;

                    if (newHealth <= best[row][col])
                        continue;

                    best[row][col] = newHealth;
                    q.push({row, col, newHealth});
                }
            }
        }
        return false;
    }
};