
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            int cnt[11] = {};

            for (int j = i; j < n; j++) {
                int x = nums[j];

                // Check whether adding x preserves
                // product equivalence using prime factors.
                int y = x;

                for (int p = 2; p <= 10; p++) {
                    while (y % p == 0) {
                        cnt[p]++;
                        y /= p;
                    }
                }

                long long prod = 1;
                long long g = 0, l = 1;

                // This approach avoids product overflow:
                // use logarithm-free factorization comparison
                // in the final version below.
                for (int k = i; k <= j; k++) {
                    g = gcd(g, (long long)nums[k]);
                    l = l / gcd(l, (long long)nums[k]) * nums[k];
                }

                // Rebuild product only when safely bounded.
                __int128 value = 1;
                bool overflow = false;

                for (int k = i; k <= j; k++) {
                    value *= nums[k];
                    if (value > (__int128)1e30) {
                        overflow = true;
                        break;
                    }
                }

                if (!overflow && value == (__int128)g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
