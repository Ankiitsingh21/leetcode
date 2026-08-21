class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        auto countValid = [&](long long x) -> long long {
            long long total = 0;

            for (int mask = 1; mask < (1 << n); mask++) {
                long long lcm = 1;
                int bits = 0;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;

                        long long g = std::gcd(lcm, (long long)coins[i]);

                        // Avoid overflow
                        lcm = (lcm / g) * coins[i];

                        if (lcm > x)
                            break;
                    }
                }

                if (lcm > x)
                    continue;

                long long cnt = x / lcm;

                if (bits % 2 == 1)
                    total += cnt;
                else
                    total -= cnt;
            }

            return total;
        };

        long long lo = 1;
        long long hi = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;

            if (countValid(mid) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};