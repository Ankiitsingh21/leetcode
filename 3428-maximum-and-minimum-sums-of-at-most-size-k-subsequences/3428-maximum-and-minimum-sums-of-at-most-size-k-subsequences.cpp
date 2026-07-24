class Solution {
    static const int MOD = 1e9 + 7;

    void buildNCR(vector<vector<long long>> &nCr, int n, int k) {

        nCr.assign(n + 1, vector<long long>(k, 0));

        // C(i,0) = 1
        for (int i = 0; i <= n; i++)
            nCr[i][0] = 1;

        // Pascal's Formula
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < k && j <= i; j++) {
                nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % MOD;
            }
        }
    }

    void buildWays(vector<long long> &ways,
                   const vector<vector<long long>> &nCr,
                   int n,
                   int k) {

        ways.assign(n + 1, 0);

        for (int i = 0; i <= n; i++) {

            long long sum = 0;

            for (int j = 0; j < k && j <= i; j++) {
                sum = (sum + nCr[i][j]) % MOD;
            }

            ways[i] = sum;
        }
    }

public:
    int minMaxSums(vector<int>& nums, int k) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<long long>> nCr;
        buildNCR(nCr, n, k);

        vector<long long> ways;
        buildWays(ways, nCr, n, k);

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            int left = i;
            int right = n - i - 1;

            long long cntMax = ways[left];
            long long cntMin = ways[right];

            ans = (ans + 1LL * nums[i] * ((cntMax + cntMin) % MOD)) % MOD;
        }

        return ans;
    }
};