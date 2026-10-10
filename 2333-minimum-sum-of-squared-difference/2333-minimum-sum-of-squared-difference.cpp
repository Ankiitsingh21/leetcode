class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = 1LL * k1 + k2;
        int n = nums1.size();

        vector<int> diff(n);
        long long total = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
        }

        if (k >= total) return 0;

        int low = 0, high = 100000;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long needed = 0;

            for (int d : diff) {
                if (d > mid) {
                    needed += d - mid;
                }
            }

            if (needed <= k)
                high = mid;
            else
                low = mid + 1;
        }

        int limit = low;
        long long remaining = k;
        long long ans = 0;

        for (int &d : diff) {
            if (d > limit) {
                remaining -= d - limit;
                d = limit;
            }
        }

        for (int &d : diff) {
            if (remaining > 0 && d == limit && limit > 0) {
                d--;
                remaining--;
            }
        }

        for (int d : diff) {
            ans += 1LL * d * d;
        }

        return ans;
    }
};