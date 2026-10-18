class Solution {
public:
    static const long long MOD = 1000000007;

    long long C[1005][1005];

    long long solve(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2)
            return 1;

        int root = nums[0];

        vector<int> left, right;

        for (int i = 1; i < n; i++) {
            if (nums[i] < root)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long leftWays = solve(left);
        long long rightWays = solve(right);

        // Number of ways to interleave left and right subtree elements
        long long interleave = C[n - 1][left.size()];

        return interleave * leftWays % MOD * rightWays % MOD;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        // Precompute combinations using Pascal's triangle
        for (int i = 0; i <= n; i++) {
            C[i][0] = C[i][i] = 1;

            for (int j = 1; j < i; j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }

        // Subtract 1 because the original ordering is not counted
        return (solve(nums) - 1 + MOD) % MOD;
    }
};