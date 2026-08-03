class Solution {
    int solve(int index, int M, int turn, vector<int>& nums,
              vector<vector<vector<int>>>& dp) {
        if (index >= nums.size())
            return 0;
        if (dp[index][M][turn] != INT_MIN)
            return dp[index][M][turn];

        if (turn == 0) {
            int ans = 0;
            int sum = 0;
            for (int X = 1; X <= 2 * M && index + X <= nums.size(); X++) {
                sum += nums[index + X - 1];
                ans = max(ans,
                          sum + solve(index + X, max(M, X), !turn, nums, dp));
            }
            return dp[index][M][turn] = ans;
        } else {
            int ans = INT_MAX;
            for (int X = 1; X <= 2 * M && index + X <= nums.size(); X++) {
                ans = min(ans, solve(index + X, max(M, X), !turn, nums, dp));
            }
            return dp[index][M][turn] = ans;
        }
    }

public:
    int stoneGameII(vector<int>& piles) {
        vector<vector<vector<int>>> dp(
            piles.size(),
            vector<vector<int>>(piles.size() + 1, vector<int>(2, INT_MIN)));
        return solve(0, 1, 0, piles, dp);
    }
};