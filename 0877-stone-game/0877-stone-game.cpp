class Solution {
    vector<vector<int>> dp;

    int solve(int i, int j, vector<int>& piles, int turn) {
        if (i > j) return 0;

        if (dp[i][j] != INT_MIN)
            return dp[i][j];

        if (turn == 0) {
            // Alice adds stones to the difference
            int takeL = piles[i] + solve(i + 1, j, piles, 1);
            int takeR = piles[j] + solve(i, j - 1, piles, 1);

            return dp[i][j] = max(takeL, takeR);
        }
        else {
            // Bob's stones subtract from Alice's difference
            int takeL = -piles[i] + solve(i + 1, j, piles, 0);
            int takeR = -piles[j] + solve(i, j - 1, piles, 0);

            // Bob wants Alice's difference to be minimum
            return dp[i][j] = min(takeL, takeR);
        }
    }

public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        dp.assign(n, vector<int>(n, INT_MIN));

        return solve(0, n - 1, piles, 0) > 0;
    }
};