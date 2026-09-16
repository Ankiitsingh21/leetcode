class Solution {
public:
    static const int MOD = 1e9 + 7;

    int numberOfSets(int n, int k) {
        int N = n + k - 1;

        vector<long long> dp(2 * k + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= N; i++) {
            for (int j = min(i, 2 * k); j >= 1; j--) {
                dp[j] = (dp[j] + dp[j - 1]) % MOD;
            }
        }

        return dp[2 * k];
    }
};