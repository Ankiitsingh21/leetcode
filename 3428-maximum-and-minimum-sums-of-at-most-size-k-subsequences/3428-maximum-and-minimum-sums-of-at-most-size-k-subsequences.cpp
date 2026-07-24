class Solution {
    const int MOD=1e9+7;
public:
    int minMaxSums(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<long long>> ncr(n + 1, vector<long long>(k, 0));
        for (int i = 0; i <= n; i++) {
            ncr[i][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < k && j <= i; j++) {
                ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % MOD;
            }
        }
        vector<long long> ways(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            long long sum = 0;
            for (int j = 0; j < k && j <= i; j++) {
                sum = (sum + ncr[i][j]) % MOD;
            }
            ways[i] = sum;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int left = i;
            int right = n - i - 1;
            int cntL = ways[left];
            int cntR = ways[right];
            ans = (ans + (1LL * nums[i] * (cntL + cntR)) % MOD) % MOD;
        }
        return ans;
    }
};