class Solution {
    int solve(int i, int n, int cap, int buy, vector<int>& arr, vector<vector<vector<int>>>& dp) {
        if (i == n) return 0;
        if (cap == 0) return 0;

        if (dp[i][buy][cap] != -1) return dp[i][buy][cap];

        if (buy) {
            return dp[i][buy][cap] = max((-arr[i] + solve(i + 1, n, cap, !buy, arr, dp)),
                                         (solve(i + 1, n, cap, buy, arr, dp)));
        } else {
            return dp[i][buy][cap] = max((arr[i] + solve(i + 1, n, cap - 1, !buy, arr, dp)),
                                         (solve(i + 1, n, cap, buy, arr, dp)));
        }
    }

public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));  // 3D dp table
        return solve(0, n, 2, 1, arr, dp);  // maxProfit with 2 transactions left and buying opportunity
    }
};
