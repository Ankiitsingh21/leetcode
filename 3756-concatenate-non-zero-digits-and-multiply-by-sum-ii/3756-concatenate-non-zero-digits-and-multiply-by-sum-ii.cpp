class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        // prefix sum of digits
        vector<long long> prefixSum(n + 1, 0);

        // cnt[i] = number of non-zero digits in s[0..i-1]
        vector<int> cnt(n + 1, 0);

        vector<int> digits;

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            prefixSum[i + 1] = prefixSum[i] + d;
            cnt[i + 1] = cnt[i] + (d != 0);

            if (d != 0)
                digits.push_back(d);
        }

        int m = digits.size();

        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<long long> prefixNum(m + 1, 0);
        for (int i = 1; i <= m; i++)
            prefixNum[i] = (prefixNum[i - 1] * 10 + digits[i - 1]) % MOD;

        vector<int> ans;

        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];

            long long sum = prefixSum[r + 1] - prefixSum[l];
            sum %= MOD;

            int left = cnt[l];
            int right = cnt[r + 1];
            int len = right - left;

            long long num = (prefixNum[right] -
                             (prefixNum[left] * pow10[len]) % MOD + MOD) %
                            MOD;

            ans.push_back((num * sum) % MOD);
        }

        return ans;
    }
};